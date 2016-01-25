#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define BUFFER_LENGTH 200

struct CommandStruct
{
    char command[10];
    size_t num_of_command_parameters;
    int positionA;
    int positionB;
    int size;
};

void error(const char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
char **string_to_arr_of_strings_by_delimiters(char *, const char *, size_t *);
int arr_of_strings_filtered_by_condition(char ***, size_t *, _Bool (*) (char *));
_Bool is_valid_curly_brackets_sequence(char *str);
char * get_sequence(char *);
void swap(void *, void *, size_t);
int get_command_parameters(char *, struct CommandStruct *);
void free_command_params(char **, size_t);

/*
 * 
 */
int main(int argc, char** argv) 
{
    size_t i;
    
    char * text = NULL;
    size_t text_buf_size;
    ssize_t text_len;
    
    if(-1 == (text_len = get_line(&text, &text_buf_size, stdin)))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    const char * delimiters = "|";
    size_t num_of_blocks;

    char ** blocks = string_to_arr_of_strings_by_delimiters(text, delimiters, 
            &num_of_blocks);

    if(NULL == blocks)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    // filter invalid curly bracket sequences inside a single block
    if(0 != arr_of_strings_filtered_by_condition(&blocks, &num_of_blocks, 
            &is_valid_curly_brackets_sequence))
    {
        return (EXIT_FAILURE);
    }
    
    size_t resulting_string_total_len = BUFFER_LENGTH;
    char * resulting_string = (char *)malloc(resulting_string_total_len);
    
    if(NULL == resulting_string)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    resulting_string[0] = '\0';
    
    char * sequence = NULL;
    size_t sequence_len;
    size_t resulting_string_current_len = 0;
    for(i = 0; i < num_of_blocks; i++)
    {
        sequence = get_sequence(blocks[i]);
        if(NULL == sequence)
        {
            return (EXIT_FAILURE);
        }
        
        sequence_len = strlen(sequence);
        
        if((resulting_string_current_len + sequence_len) >= (resulting_string_total_len - 1))
        {
            resulting_string_total_len += sequence_len;
            char *new_resulting_string = (char *)realloc(resulting_string, resulting_string_total_len);
            if(NULL == new_resulting_string)
            {
                error("Error when realloc!", false);
                return (EXIT_FAILURE);
            }
            
            resulting_string = new_resulting_string;            
        }
            
        strcat(resulting_string, sequence);
        resulting_string_current_len += sequence_len;
    }    
    
    char * command = NULL;
    size_t command_buf_size = 0;
    ssize_t command_len;
    char * end_command = "end";
    
    struct CommandStruct command_struct;
    
    while(-1 != (command_len = get_line(&command, &command_buf_size, stdin)))
    {
        int ret = get_command_parameters(command, &command_struct);
        
        if(ret == 0 && strcmp(command_struct.command, end_command) == 0)
            break;
        
        if(ret == -3 || ret == -4 || ret == -5)
        {
            printf("Invalid command parameters\n");
            continue;
        }

        if(ret == 0 && (command_struct.positionA < 0 
                || command_struct.positionB < 0 || command_struct.size < 0 
                || (command_struct.positionA + command_struct.size) > strlen(resulting_string)
                || (command_struct.positionB + command_struct.size) > strlen(resulting_string)
                || (command_struct.positionA + command_struct.size) > command_struct.positionB))
        {
            printf("Invalid command parameters\n");
            continue;
        }

        swap((char *)(resulting_string + command_struct.positionA), 
                (char *)(resulting_string + command_struct.positionB), 
                command_struct.size);
    }  
    
    /* Print output */
    
    printf("%s\n", resulting_string);
    
    /* Free allocated resources */
    
    if(command)
        free(command);
    
    if(resulting_string)
        free(resulting_string);
    
    for(i = 0; i < num_of_blocks; i++)
    {
        if(blocks[i])
            free(blocks[i]);
    }
    
    if(blocks)
        free(blocks);
    
    if(text)
        free(text);
    
    return (EXIT_SUCCESS);
}

void error(const char *msg, _Bool output_to_log_file)
{
    if (errno)
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    else
        fprintf(stderr, "%s\n", msg);
    
    if(output_to_log_file)
    {
        FILE * logfile = fopen("log.txt", "a");
        if(logfile)
        {
            printf("\n---------------------------------------\n");
            if (errno)
                fprintf(logfile, "%s: %s\n", msg, strerror(errno));
            else
                fprintf(logfile, "%s\n", msg);

            free(logfile);
        }
    }
}

ssize_t get_line(char **lineptr, size_t *buf_size, FILE *stream)
{
    /* Sanity checks. */
    if (lineptr == NULL || buf_size == NULL || stream == NULL)
        return -1;
    
    /* Allocate the line the first time. */
    if (*lineptr == NULL)
    {
        errno = 0;
        *lineptr = (char *)malloc(BUFFER_LENGTH);        
        if(NULL == *lineptr)
        {
            error("Error when malloc() in get_line() function.", false);
            return -1;
        }
        *buf_size = BUFFER_LENGTH;
    }
    
    size_t i = 0;
    char ch;
    while((ch = getc(stream)) != '\n' && ch != EOF)
    {
        if(i == (*buf_size - 1))
        {
            errno = 0;
            char *newLine = (char *)realloc(*lineptr, *buf_size + BUFFER_LENGTH);
            if(NULL == newLine)
            {
                if(*lineptr)
                    free(*lineptr);
                
                error("Error when realloc in get_line() function.", false);
                return -1;
            }
            
            *lineptr = newLine;
            *buf_size += BUFFER_LENGTH;
        }
        
        (*lineptr)[i++] = ch;
    }
    
    (*lineptr)[i] = '\0';
    
    return (ssize_t)i; 
}

char **string_to_arr_of_strings_by_delimiters(char *buffer, 
        const char *delimiters, size_t *count)
{
    char *ptr = buffer;
    *count = 0;
    
    char *token;
    char *savePtr;
    
    /* get the first token */
    if (NULL != (token = strtok_r(buffer, delimiters, &savePtr)))
    {
        (*count)++;

        /* walk through other tokens */
        while (NULL != (token = strtok_r(NULL, delimiters, &savePtr)))
        {
            (*count)++;
        }
    }
    
    errno = 0;
    char **arr = (char **)malloc((*count) * sizeof(char *));
    if(NULL == arr)
    {
        error("Not enough memory!", false);
        return NULL;
    }
    
    int i, len;
    for(i = 0; i < *count; i++)
    {
        // skip delimeters
        while(*ptr != 0 && NULL != strchr(delimiters, *ptr))
        {
            ptr++;
        }
        
        len = strlen(ptr) + 1;
        
        errno = 0;
        arr[i] = (char *)malloc(len);
        if(NULL == arr[i])
        {
            error("Not enough memory!", false);
            return NULL;
        }
        
        strncpy(arr[i], ptr, len);
               
        ptr += len;
    }
    
    return arr; // must free it in the calling function
}

int arr_of_strings_filtered_by_condition(char ***arr, size_t *count, 
        _Bool (*condition) (char *))
{
    errno = 0;
    char **new_arr = (char **)malloc(*count * sizeof(char *));
    if(errno != 0)
    {
        error("Not enough memory!", false);
        return (EXIT_FAILURE);
    }
    
    size_t i, new_count = 0;
    
    for(i = 0; i < *count; i++)
    {
        if(false == condition((*arr)[i]))
        {
            free((*arr)[i]);
            (*arr)[i] = NULL;
            
            continue;
        }
        
        errno = 0;
        new_arr[new_count] = (char *)malloc(strlen((*arr)[i]) + 1);
        if(errno != 0)
        {
            error("Not enough memory!", false);
            return (EXIT_FAILURE);
        }
        
        strcpy(new_arr[new_count], (*arr)[i]);
        new_count++;
    }
    
    if(new_count > 0)
    {
        errno = 0;
        char ** small_arr = (char **)realloc(new_arr, new_count * sizeof(char *));
        if(errno != 0)
        {
            error("Error when realloc!", false);
            return (EXIT_FAILURE);
        }
        
        for(i = 0; i < *count; i++)
        {
            if(NULL != (*arr)[i])
            {
                free((*arr)[i]);
            }
        }
        
        free(*arr);
        
        *arr = small_arr;
        *count = new_count;
    }
    
    return 0;
}

_Bool is_valid_curly_brackets_sequence(char *str)
{
    char * openning_curly_bracket = strchr(str, '{');
    if(NULL == openning_curly_bracket)
        return false;
    
    char * closinging_curly_bracket = strchr(openning_curly_bracket, '}');
    if(NULL == closinging_curly_bracket)
        return false;

    if((closinging_curly_bracket - openning_curly_bracket) <= 1)
        return false;
    
    return true;
}

char * get_sequence(char * str)
{
    char * openning_curly_bracket = strchr(str, '{');
    if(NULL == openning_curly_bracket)
        return NULL;
    
    char * closinging_curly_bracket = strchr(openning_curly_bracket, '}');
    if(NULL == closinging_curly_bracket)
        return NULL;
    
    if((closinging_curly_bracket - openning_curly_bracket) <= 1)
        return NULL;
    
    *closinging_curly_bracket = '\0';
    
    return (openning_curly_bracket + 1);
}

void swap(void *ptr1, void *ptr2, size_t size)
{
    void *tmp = malloc(size);
    if(NULL != tmp)
    {
        memcpy(tmp, ptr1, size);
        memcpy(ptr1, ptr2, size);
        memcpy(ptr2, tmp, size);
        
        free(tmp);
    }
}

int get_command_parameters(char * command, 
        struct CommandStruct * command_struct)
{
    size_t i;
    char ** command_parameters = NULL;
    
    command_parameters = 
            string_to_arr_of_strings_by_delimiters(command, " ", 
                &(command_struct->num_of_command_parameters));

    if(NULL == command_parameters)
        return -1;
    
    if(command_struct->num_of_command_parameters == 1)
    {
        strcpy(command_struct->command, command_parameters[0]);
        
        free_command_params(command_parameters, 
                    command_struct->num_of_command_parameters);
        
        return 0;
    }
        
    if(command_struct->num_of_command_parameters != 4)
    {
        free_command_params(command_parameters, 
                    command_struct->num_of_command_parameters);

        return -3;
    }
        
    if(strcmp(command_parameters[0], "swap") != 0)
    {
        free_command_params(command_parameters, 
                    command_struct->num_of_command_parameters);
        
        return -4;
    }
        
    size_t j;
    _Bool is_digit = true;
    for(i = 1; i < 4; i++)
    {
        for(j = 0; j < strlen(command_parameters[i]); j++)
        {
            if(!isdigit(command_parameters[i][j]))
            {
                is_digit = false;
                break;
            }
        }
    }
        
    if(is_digit == false)
    {
        free_command_params(command_parameters, 
                    command_struct->num_of_command_parameters);

        return -5;
    }
    
    strcpy(command_struct->command, command_parameters[0]);
    command_struct->positionA = atoi(command_parameters[1]);
    command_struct->positionB = atoi(command_parameters[2]);
    command_struct->size = atoi(command_parameters[3]);
    
    free_command_params(command_parameters, 
                    command_struct->num_of_command_parameters);
    
    return 0;
}

void free_command_params(char ** arr, size_t len)
{
    size_t i;
    for(i = 0; i < len; i++)
    {
        if(arr[i])
            free(arr[i]);
    }

    if(arr)
        free(arr);
}