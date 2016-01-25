#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 8

void error(char *);
char *get_line(void);

/*
 * Problem 10. Line Reading Function
 * 
 * Write a function that reads an entire line from the standard input stream 
 * (console) and returns a pointer to the read string. The function should be 
 * able to read lines of unknown size.
 * 
 * Hint: Initially allocate a small buffer(use malloc()) and increase its size 
 * when it gets full (use realloc()).
 * 
 * Forbidden: Do not use hacks such as declaring very large buffers.
 */
int main() 
{
    printf("Input string with any length:\n");
    char *line = get_line();
    
    if(NULL != line)
    {
        printf("\nResult:\n%s\n", line);
        
        free(line);
    }

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    if(errno != 0)
    {
        fprintf(stderr, "%s", strerror(errno));
    }
    perror(msg);
    //return (EXIT_FAILURE);
}

char *get_line(void)
{
    errno = 0;
    
    char *line = (char *)malloc(BUFFER_LENGTH);
    if(NULL == line)
    {
        error("Error when malloc() in get_line() function.\n");
        return NULL;
    }
    
    size_t i = 0;
    size_t total_length = BUFFER_LENGTH - 1;
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(i >= total_length)
        {
            char *newLine = (char *)realloc(line, total_length + BUFFER_LENGTH);
            if(NULL == newLine)
            {
                error("Error when realloc in get_line() function.\n");
                return NULL;
            }
            
            total_length += BUFFER_LENGTH;
            line = newLine;
        }
        
        line[i++] = ch;
    }
    
    line[i] = '\0';
    
    return line;
}