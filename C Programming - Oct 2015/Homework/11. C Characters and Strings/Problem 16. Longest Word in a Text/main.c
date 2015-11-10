#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);
char * get_longest_word_position(char *, const char *);

/*
 * Problem 16. Longest Word in a Text
 * 
 * Write a program to find the longest word in a text. Examples:
 * 
 * ----------------------------------------------------------------------------
 *                   Input                   |            Output
 * ----------------------------------------------------------------------------
 * Welcome to the Software University.       | University
 * ----------------------------------------------------------------------------
 * The C# Basics course is awesome start in  | programming
 * programming with C# and Visual Studio.    |
 * ----------------------------------------------------------------------------
 */
int main() 
{
    char * line = NULL;
    size_t buf_size = 0;
    char * delimiters = " ,.!?";
    char * longest_word_position;
    
    printf("Input:");
    if(-1 == get_line(&line, &buf_size, stdin))
    {
        error("Error", false);
            return (EXIT_FAILURE);
    }
    
    longest_word_position = get_longest_word_position(line, delimiters);
    
    printf("\n Output\n");
    printf("%s\n", longest_word_position);
    
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

char * get_longest_word_position(char *text, const char *delimiters)
{
    char *position = text;
    size_t word_with_max_len = 0;
    
    char *token;
    char *savePtr;
    
    /* get the first token */
    if (NULL != (token = strtok_r(position, delimiters, &savePtr)))
    {
        if(strlen(token) > word_with_max_len)
        {
            position = token;
            word_with_max_len = strlen(token);
        }

        /* walk through other tokens */
        while (NULL != (token = strtok_r(NULL, delimiters, &savePtr)))
        {
            if(strlen(token) > word_with_max_len)
            {
                position = token;
                word_with_max_len = strlen(token);
            }
        }
    }
    
    return position;
}