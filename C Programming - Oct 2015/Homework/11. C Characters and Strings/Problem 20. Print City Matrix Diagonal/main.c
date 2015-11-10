#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
char **string_to_arr_of_strings_by_delimiters(char *, char *, size_t *);

/*
 * Problem 20. * Print City Matrix Diagonal
 * 
 * You are given a square matrix of city names. Your task is to print the 
 * names of those cities which are stationed on the matrix's main diagonal. 
 * On the first input line you are given the count of the rows. The names of 
 * the cities will consist of one word only.
 * 
 * ----------------------------------------------------------------------------
 *                   Input                   |            Output
 * ----------------------------------------------------------------------------
 * 4                                         | Sofia
 * Sofia Burgas Aitos Pleven                 | Skopie
 * Varna Skopie Athens Burkley               | Svishtov
 * London Plovdiv Svishtov Ohrid             | Manchester
 * Paris Vienna Berlin Manchester            |
 * ----------------------------------------------------------------------------
 * 3                                         | Moscow
 * Moscow Brussels Luxemburg                 | Madrid
 * Varna Madrid Lissabon                     | Pleven
 * Munchen Copenhagen Pleven                 |
 * ----------------------------------------------------------------------------
 * 1                                         | Yorkshire
 * Yorkshire                                 |
 * ----------------------------------------------------------------------------
 */
int main() 
{
    size_t num_lines;
    size_t num_cities_per_line;
     
    char * line = NULL;
    size_t line_buf_size = 0;
    
    printf("Number of lines:");
    scanf("%lu", &num_lines);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    char ***input = (char ***)malloc(num_lines * sizeof(char **));
    if(NULL == input)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i, j;
    ssize_t len;
    for(i = 0; i < num_lines; i++)
    {
        if(-1 == (len = get_line(&line, &line_buf_size, stdin)))
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }
        
        char * delimiters = " ";       
        
        input[i] = string_to_arr_of_strings_by_delimiters(line, delimiters, 
                &num_cities_per_line);
        
        if(NULL == input[i] || num_lines != num_cities_per_line)
        {
            free(input);
            
            error("Error", false);
            return (EXIT_FAILURE);
        }
    }
    
    printf("\n Output\n");
    for(i = 0; i < num_lines; i++)
    {
        for(j = 0; j < num_cities_per_line; j++)
        {
            if(i == j)
            {
                printf("%s\n", input[i][j]);
            }
        }
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < num_lines; i++)
    {
        for(j = 0; j < num_cities_per_line; j++)
        {
            if(input[i][j])
                free(input[i][j]);
        }
        
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