#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(char *, _Bool);
ssize_t get_line(char **, size_t *, FILE *);

/*
 * Problem 13. Read Line Function
 * 
 * Write a function that reads an entire line from the standard input stream 
 * (until end of line ('\n') or end of file (EOF) and returns a pointer to the 
 * read string. The function should be able to read lines of unknown size.
 * 
 * The returned string's length should be equal to its allocated memory.
 */
int main() 
{
    char * line = NULL;
    size_t buf_size = 0;
    
    printf(" Input:");
    if(-1 == get_line(&line, &buf_size, stdin))
    {
        error("get_line() function returns NULL.", false);
        return (EXIT_FAILURE);
    }    
    
    printf("\nOutput:");
    printf("%s\n", line);    
    printf("\nLength: %zd\n", strlen(line));
    
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