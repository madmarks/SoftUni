#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
void replace_series(char *, ssize_t *);

/*
 * Problem 03. Series of Letters
 * 
 * Write a program that reads a string from the console and replaces all series 
 * of consecutive identical letters with a single one.
 * 
 * Input                                           | Output
 * ----------------------------------------------------------------------------
 * aaaaabbbbbcdddeeeedssaa                         | abcdedsa
 * ---------------------------------------------------------------------------- 
 */
int main() 
{    
    size_t len = BUFFER_LENGTH; // initial size of buffer
    ssize_t read;
    
    errno = 0;
    char *line = (char *)malloc(len);
    if(NULL == line)
    {
        error("Not enough memory!");
        return (EXIT_FAILURE);
    }
    
    printf("Input string:");
    if((read = getline(&line, &len, stdin)) != -1)
    {
        if(read > 0 && line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
            read--;
        }
        
        replace_series(line, &read);

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

void replace_series(char *str, ssize_t *len)
{
    ssize_t new_len = 0;
    ssize_t i = 0;
    
    while(i < *len)
    {
        str[new_len] = str[i];
        i++;
    
        while(i < *len && str[new_len] == str[i])
        {
            i++;
        }
        
        new_len++;
    }
    
    *len = new_len;
    str[*len] = '\0';
}