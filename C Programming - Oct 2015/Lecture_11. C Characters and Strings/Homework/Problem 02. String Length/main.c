#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 100

void error(char *);

/*
 * Problem 02. String Length
 * 
 * Write a program that reads from the console a string of maximum 20 
 * characters. If the length of the string is less than 20, the rest of the 
 * characters should be filled with asterisks '*'. 
 * Print the resulting string on the console.
 * 
 * Input                                           | Output
 * ----------------------------------------------------------------------------
 * Welcome to SoftUni!                             | Welcome to SoftUni!*
 * ---------------------------------------------------------------------------- 
 * a regular expression (abbreviated regex or      | a regular expression
 * regexp and sometimes called a rational          |
 * expression) is a sequence of characters that    |
 * forms a search pattern                          |
 * ----------------------------------------------------------------------------
 * C#                                              | C#******************
 * ----------------------------------------------------------------------------
 */
int main() 
{
    size_t buf_len = BUFFER_LENGTH; // initial size of buffer
    ssize_t read;
    
    errno = 0;
    char *line = (char *)malloc(buf_len);
    if(NULL == line)
    {
        error("Not enough memory!");
        return (EXIT_FAILURE);
    }
    
    printf("Input string:");
    if((read = getline(&line, &buf_len, stdin)) != -1)
    {
        if(read > 0 && line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
            read--;
        }
        
        size_t maxLen = 20;
        if(read < maxLen)
        {
            size_t i;
            for(i = read; i < maxLen; i++)
            {
                line[i] = '*';
            }
            
        }
        line[maxLen] = '\0';

        printf("\n Output\n");
        printf("%s\n", line);
    }

    free(line);

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    if(errno != 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }
    perror(msg);
}