#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 1000

void error(char *);
char *replaceDigits(char *, int *);

/*
 * Problem 06. Digit Hate
 * 
 * Write a function that takes a string as input and replaces all occurrences of 
 * a digit (0-9) with a slash '/'. 
 * 
 * The function should NOT modify the original string. It should return the 
 * resulting string as result. The function should also notify the calling 
 * function how many digits were replaced. Find a way to do this using pointer 
 * parameters.
 * 
 * Tip:Be careful where you allocate the resulting string.
 * 
 * Input
 * The Cold War is believed to be between the period 1947-1999.
 * 
 * Output
 * The Cold War is believed to be between the period ////-////.
 */
int main() 
{
    char buffer[BUFFER_LENGTH];
    
    printf(" Input:\n");
    if(NULL == fgets(buffer, BUFFER_LENGTH, stdin))
    {
        error("fgets(...) returns NULL!");
    }
    
    int len = strlen(buffer);
    if(buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    /* Replace digits */
    
    int count_replaced;
    char *result = replaceDigits(buffer, &count_replaced);    
    
    /* Print result */
    
    printf("\n Output:\n%s\nReplaced: %d ", result, count_replaced);
    if(count_replaced == 1)
        printf("character\n");
    else
        printf("characters\n");
    
    /* Free allocated memory */
    
    free(result);

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

char *replaceDigits(char *src, int *replaced)
{
    *replaced = 0;
    
    int len = strlen(src) + 1; // + 1 , because of '\0'
    
    char *res = (char *)malloc(len);
    
    int i = 0;
    while(i < len)
    {
        if('0' <= src[i] && src[i] <= '9')
        {
            res[i] = '/';
            (*replaced)++;
        }
        else
        {
            res[i] = src[i];
        }
        
        i++;
    }
    
    return res;
}