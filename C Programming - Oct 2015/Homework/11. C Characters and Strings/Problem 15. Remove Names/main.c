#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
char **string_to_arr_of_strings_by_delimiters(char *, char *, size_t *);
int arr_of_strings_filtered_by_list_of_strings(char ***, size_t *, 
        char **, size_t);
_Bool areEqual(const char *, size_t, const char *, size_t);

/*
 * Problem 15. Remove Names
 * 
 * Write a program that takes as input two lists of names and removes from the 
 * first list all names given in the second list. The input and output lists are 
 * given as words, separated by a space, each list at a separate line. 
 * 
 * Examples:
 * 
 * ----------------------------------------------------------------------------
 *                   Input                   |            Output
 * ----------------------------------------------------------------------------
 * Peter Alex Maria Todor Steve Diana Steve  | Peter Alex Maria Diana
 * Todor Steve Nakov                         |
 * ----------------------------------------------------------------------------
 * Hristo Hristo Nakov Nakov Petya           | Hristo Hristo Petya
 * Nakov Vanessa Maria                       | 
 * ----------------------------------------------------------------------------
 */
int main() 
{
    char * line = NULL;
    size_t buf_size = 0;
    char * delimiters = " ";
    
    char ** names1_list;
    char ** names2_list;
    
    size_t names1_size;
    size_t names2_size;    
    
    printf("First list: ");
    if(-1 == get_line(&line, &buf_size, stdin))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }    
    
    names1_list = 
        string_to_arr_of_strings_by_delimiters(line, delimiters, &names1_size);
    
    if(NULL == names1_list)
    {
        if(line)
            free(line);
        
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    //
    
    printf("Second list: ");
    if(-1 == get_line(&line, &buf_size, stdin))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }    
    
    names2_list = 
        string_to_arr_of_strings_by_delimiters(line, delimiters, &names2_size);
    
    if(NULL == names2_list)
    {
        if(line)
            free(line);
        
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    if(0 != arr_of_strings_filtered_by_list_of_strings(&names1_list, 
            &names1_size, names2_list, names2_size))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    printf("\n Output\n");
    size_t i;
    for(i = 0; i < names1_size; i++)
    {
        printf("%s ", names1_list[i]);
    }
    printf("\n");
    
    /* Free memory allocations */
    
    for(i = 0; i < names1_size; i++)
    {
        if(names1_list[i])
            free(names1_list[i]);
    }
    if(names1_list)
        free(names1_list);
    
    for(i = 0; i < names2_size; i++)
    {
        if(names2_list[i])
            free(names2_list[i]);
    }
    if(names2_list)
        free(names2_list);
    
    if(line)
        free(line);

    return (EXIT_SUCCESS);
}

void error(char *msg, _Bool output_to_log_file)
{
    if (errno)
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    else
        fprintf(stderr, "%s\n", strerror(errno));
    
    if(output_to_log_file)
    {
        FILE * logfile = fopen("log.txt", "a");
        if(logfile)
        {
            printf("\n---------------------------------------\n");
            if (errno)
                fprintf(logfile, "%s: %s\n", msg, strerror(errno));
            else
                fprintf(logfile, "%s\n", strerror(errno));

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
    
    return (ssize_t)(i + 1); 
}

char **string_to_arr_of_strings_by_delimiters(char *buffer, char *delimiters, 
        size_t *count)
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

_Bool areEqual(const char * a, size_t a_len, const char * b, size_t b_len)
{
    if(a_len != b_len)
        return false;
    
    size_t i = 0;
    while(i < a_len)
    {
        if(a[i] != b[i])
            return false;
        
        i++;
    }
    
    return true;
}

int arr_of_strings_filtered_by_list_of_strings(char ***arr, size_t *count, 
        char **list, size_t list_len)
{
    errno = 0;
    char **new_arr = (char **)malloc(*count * sizeof(char *));
    if(NULL == new_arr)
    {
        error("Not enough memory!", false);
        return (EXIT_FAILURE);
    }
    
    size_t i, j, new_count = 0;
    
    for(i = 0; i < *count; i++)
    {
        for(j = 0; j < list_len; j++)
        {
            if(areEqual((*arr)[i], strlen((*arr)[i]), list[j], strlen(list[j])))
            {
                free((*arr)[i]);
                (*arr)[i] = NULL;
                
                break;
            }
        }     
        
        if(j == list_len)
        {
            errno = 0;
            new_arr[new_count] = (char *)malloc(strlen((*arr)[i]) + 1);
            if(NULL == new_arr[new_count])
            {
                for(j = 0; j < new_count; j++)
                {
                    free(new_arr[j]);
                }
                free(new_arr);

                error("Not enough memory!", false);
                return (EXIT_FAILURE);
            }

            strcpy(new_arr[new_count], (*arr)[i]); 
            new_count++;
        }
    }
    
    if(new_count > 0)
    {
        errno = 0;
        char ** small_arr = (char **)realloc(new_arr, new_count * sizeof(char *));
        if(NULL == small_arr)
        {
            for(j = 0; j < new_count; j++)
            {
                free(new_arr[j]);
            }
            free(new_arr);
            
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