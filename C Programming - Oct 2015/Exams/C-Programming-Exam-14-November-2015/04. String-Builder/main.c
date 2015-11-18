#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define BUFFER_LENGTH 256

struct CommandStruct 
{
    char command[10];
    size_t num_of_command_parameters;
    int positionA;
    int positionB;
    int size;
};

ssize_t get_line(char **, size_t *, FILE *);
char ** string_to_arr_of_strings_by_delimiters(char *, const char *, size_t *);
int str_concat(char **, size_t *, const char *);
int str_insert(char **, size_t *, const char *, size_t);
int str_replace(char **, size_t *, const char *, const char *);
void free_command_params(char **, size_t);

/*
 * 
 */
int main(int argc, char** argv) 
{
    size_t result_total_len = BUFFER_LENGTH;
    char * result = (char *) malloc(result_total_len);

    if (NULL == result) 
    {
        return (EXIT_FAILURE);
    }
    result[0] = '\0';

    char * command = NULL;
    size_t command_buf_size = 0;
    ssize_t command_len;

    while (-1 != (command_len = get_line(&command, &command_buf_size, stdin))) 
    {
        size_t i;
        char ** command_params = NULL;
        size_t params_len;

        command_params =
                string_to_arr_of_strings_by_delimiters(command, "-", &params_len);

        if (NULL == command_params)
        {
            free(command);
            return -1;
        }

        if (strcmp(command_params[0], "over") == 0)
        {
            free_command_params(command_params, params_len);
            break;
        }

        if (strcmp(command_params[0], "concat") == 0) 
        {
            char * str = command_params[1];
          
            if(0 != str_concat(&result, &result_total_len, str))
            {
                free_command_params(command_params, params_len);
                free(command);
                free(result);
                return -1;
            }
        } 
        else if (strcmp(command_params[0], "insert") == 0) 
        {
            char * str = command_params[1];
            int position = atoi(command_params[2]);
            
            if(0 != str_insert(&result, &result_total_len, str, position))
            {
                free_command_params(command_params, params_len);
                free(command);
                free(result);
                return -1;
            }
        } 
        else if (strcmp(command_params[0], "replace") == 0) 
        {
            char * find = command_params[1];
            char * replace = command_params[2];
            
            if(0 != str_replace(&result, &result_total_len, find, replace))
            {
                free_command_params(command_params, params_len);
                free(command);
                free(result);
                return -1;
            }
        }

        /* Free allocated resources */

        free_command_params(command_params, params_len);
    }

    /* Print output */

    printf("%s\n", result);

    /* Free allocated resources */
    
    if(result)
        free(result);

    if (command)
        free(command);

    return (EXIT_SUCCESS);
}

ssize_t get_line(char **lineptr, size_t *buf_size, FILE *stream) {
    /* Sanity checks. */
    if (lineptr == NULL || buf_size == NULL || stream == NULL)
        return -1;

    /* Allocate the line the first time. */
    if (*lineptr == NULL) {
        errno = 0;
        *lineptr = (char *) malloc(BUFFER_LENGTH);
        if (NULL == *lineptr) {
            //error("Error when malloc() in get_line() function.", false);
            return -1;
        }
        *buf_size = BUFFER_LENGTH;
    }

    size_t i = 0;
    char ch;
    while ((ch = getc(stream)) != '\n' && ch != EOF) {
        if (i == (*buf_size - 1)) {
            errno = 0;
            char *newLine = (char *) realloc(*lineptr, *buf_size + BUFFER_LENGTH);
            if (NULL == newLine) {
                if (*lineptr)
                    free(*lineptr);

                //error("Error when realloc in get_line() function.", false);
                return -1;
            }

            *lineptr = newLine;
            *buf_size += BUFFER_LENGTH;
        }

        (*lineptr)[i++] = ch;
    }

    (*lineptr)[i] = '\0';

    return (ssize_t) i;
}

char **string_to_arr_of_strings_by_delimiters(char *buffer,
        const char *delimiters, size_t *count) {
    char *ptr = buffer;
    *count = 0;

    char *token;
    char *savePtr;

    /* get the first token */
    if (NULL != (token = strtok_r(buffer, delimiters, &savePtr))) {
        (*count)++;

        /* walk through other tokens */
        while (NULL != (token = strtok_r(NULL, delimiters, &savePtr))) {
            (*count)++;
        }
    }

    errno = 0;
    char **arr = (char **) malloc((*count) * sizeof (char *));
    if (NULL == arr) {
        return NULL;
    }

    int i, len;
    for (i = 0; i < *count; i++) {
        // skip delimeters
        while (*ptr != 0 && NULL != strchr(delimiters, *ptr)) 
        {
            ptr++;
        }

        len = strlen(ptr) + 1;

        errno = 0;
        arr[i] = (char *) malloc(len);
        if (NULL == arr[i]) {
            return NULL;
        }

        strncpy(arr[i], ptr, len);

        ptr += len;
    }

    return arr; // must free it in the calling function
}

int str_concat(char ** str, size_t * str_buf_len, const char * str2)
{
    size_t len = strlen(*str);
    size_t len2 = strlen(str2);
    
    if(len + len2 >= *str_buf_len)
    {
        while(len + len2 >= *str_buf_len)
            *str_buf_len += BUFFER_LENGTH;
        
        // reallocate new string
        char * tmp = (char *)realloc(*str, *str_buf_len);
        if (NULL == tmp) 
        {
            return -1;
        }

        *str = tmp;
    }

    strcat(*str, str2);
    
    return 0;
}

int str_insert(char ** str, size_t * str_buf_len, const char * str2, size_t pos) 
{    
    // lenght of first and second strings
    size_t len = strlen(*str);
    size_t len2 = strlen(str2);
    
    if(len + len2 >= *str_buf_len)
    {
        while(len + len2 >= *str_buf_len)
            *str_buf_len += BUFFER_LENGTH;
        
        // reallocate new string
        char *tmp = (char *)realloc(*str, *str_buf_len);
        if (NULL == tmp) 
        {
            return -1;
        }

        *str = tmp;
    }
    
    memmove(*str + pos + len2, *str + pos, len - pos);
    memcpy(*str + pos, str2, len2);
    (*str)[len + len2] = '\0';
    
    return 0;
}

int str_replace(char ** str, size_t * str_buf_len, 
        const char * find, const char * replace) 
{
    char * str_begin = *str;
    char * target; // Will store our new string
    char * final; // Will use to store the pointer of the final string
    char * ptr = *str; // Will use for searching
    int matches = 0;

    // First count the matches 
    
    while (NULL != (ptr = strstr(ptr, find))) 
    {
        matches++;
        ptr++;
    }
    
    size_t len = strlen(*str);
    long int diff = matches * (strlen(replace) - strlen(find));
    
    if(len + diff >= *str_buf_len)
    {
        while(len + diff >= *str_buf_len)
            *str_buf_len += BUFFER_LENGTH;
    }

    target = (char *)calloc(*str_buf_len, 1);
    if (target == NULL) 
    {
        return -1;
    }

    final = target;

    // Now copy everything 
    
    ptr = *str;
    while (NULL != (ptr = strstr(ptr, find))) 
    {
        // Copy string before the match
        if (ptr > *str) 
        {
            strncpy(target, *str, (ptr - *str));
            target += (ptr - *str);
            *str += (ptr - *str);
        }

        // Copy replacement 
        strncpy(target, replace, strlen(replace));

        // Move pointers
        ptr += strlen(find); // Move past the match in our searching pointer
        *str += strlen(find); // Move past the string in our str
        target += strlen(replace); // Move past the replacement in our target
    }
    
    // Finally copy the rest of the string, if there's some left
    if ('\0' != **str)
    {
        strncpy(target, *str, strlen(*str));
        target += strlen(*str);
    }
    
    *target = '\0';
    
    free(str_begin);
    *str = final;    
    
    return 0;
}

void free_command_params(char ** arr, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        if (arr[i])
            free(arr[i]);
    }

    if (arr)
        free(arr);
}