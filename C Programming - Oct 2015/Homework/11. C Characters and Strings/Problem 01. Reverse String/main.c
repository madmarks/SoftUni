#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
void reverse_string(char *, ssize_t);

/*
 * Problem 01. Reverse String
 * 
 * Write a program that reads a string from the console, reverses it and 
 * prints the result back at the console.
 * 
 *         Input       |       Output
 * -----------------------------------------
 * sample              | elpmas
 * -----------------------------------------
 * 24tvcoi92           | 29iocvt42
 * -----------------------------------------
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
        
        reverse_string(line, read);

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

void reverse_string(char *str, ssize_t len)
{
    ssize_t i;
    for(i = 0; i < len/2; i++)
    {
        str[i] ^= str[len - 1 - i];
        str[len - 1 - i] ^= str[i];
        str[i] ^= str[len - 1 - i];
    }
}