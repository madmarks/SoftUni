#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
ssize_t get_idx_of_longest_area_in_arr_of_strings(char **, size_t, int *);

/*
 * Problem 18. Longest Area in Array
 * 
 * Write a program to find the longest area of equal elements in array of 
 * strings. You first should read an integer n and n strings (each at a separate 
 * line), then find and print the longest sequence of equal elements (first its 
 * length, then its elements). If multiple sequences have the same maximal 
 * length, print the leftmost of them. Examples:
 * 
 * ----------------------------------------------------------------------------
 *                   Input                   |            Output
 * ----------------------------------------------------------------------------
 * 6                                         | 3
 * hi                                        | ok
 * hi                                        | ok
 * hello                                     | ok
 * ok                                        |
 * ok                                        |
 * ok                                        |
 * ----------------------------------------------------------------------------
 * 2                                         | 2
 * SoftUni                                   | SoftUni
 * Hello                                     |
 * ----------------------------------------------------------------------------
 * 4                                         | 4
 * hi                                        | hi
 * hi                                        | hi
 * hi                                        | hi
 * hi                                        | hi
 * ----------------------------------------------------------------------------
 * 5                                         | 2
 * wow                                       | hi
 * hi                                        | hi
 * hi                                        |
 * ok                                        |
 * ok                                        |
 * ----------------------------------------------------------------------------
 */
int main() 
{
    int num_lines;
    char * line = NULL;
    size_t line_buf_size = 0;
    
    printf("Number of lines:");
    scanf("%d", &num_lines);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    char **input = (char **)malloc(num_lines * sizeof(char *));
    if(NULL == input)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i;
    ssize_t len;
    for(i = 0; i < num_lines; i++)
    {
        if(-1 == (len = get_line(&line, &line_buf_size, stdin)))
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }
        
        input[i] = (char *)malloc(len + 1);
        if(NULL == input[i])
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }            

        strcpy(input[i], line);
    }
    
    ssize_t idx_of_longest_area;
    int len_of_longest_area;
    
    if(-1 == (idx_of_longest_area = get_idx_of_longest_area_in_arr_of_strings(
            input, num_lines, &len_of_longest_area)))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }    
    
    printf("\n Output\n");
    printf("%d\n", len_of_longest_area);
    for(i = 0; i < len_of_longest_area; i++)
    {
        printf("%s\n", input[idx_of_longest_area]);
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < num_lines; i++)
    {
        if(input[i])
            free(input[i]);
    }
    
    if(input)
        free(input);
    
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

ssize_t get_idx_of_longest_area_in_arr_of_strings(char **arr, 
        size_t len, int *num)
{
    size_t i;
    if(arr == NULL || len <= 0)
        return -1;
    
    i = 0;
    while(i < len)
    {
        if(arr[i++] == NULL)
            return -1;
    }    
    
    ssize_t idx_of_longest_area = 0;
    int len_of_longest_area = 1;
    
    ssize_t first_idx_of_current_area;
    int len_of_current_area;
    
    i = 0;
    while(i < len)
    {
        first_idx_of_current_area = i;
        len_of_current_area = 1;       
        i++;
        
        while(i < len)
        {
            if(0 == strcmp(arr[first_idx_of_current_area], arr[i]))
            {                
                len_of_current_area++;
                
                if(len_of_current_area > len_of_longest_area)
                {
                    idx_of_longest_area = first_idx_of_current_area;
                    len_of_longest_area = len_of_current_area;
                }
                
                i++;
            }
            else
            {
                break;
            }
        }
    }
    
    *num = len_of_longest_area;
    return idx_of_longest_area;
}