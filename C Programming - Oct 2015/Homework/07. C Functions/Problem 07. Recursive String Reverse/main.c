#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH_MAX 200

void reverse(char *source, int len, char *dest);

/*
 * Problem 7. Recursive String Reverse
 * 
 * Write a recursive string reverse function. The function should 
 * accept a source string and destination string as arguments. 
 * Do not use loops.
 */
int main() 
{
    char source[STRING_LENGTH_MAX];
    char dest[STRING_LENGTH_MAX];
    
    printf("Input string: ");
    fgets(source, STRING_LENGTH_MAX, stdin);
    
    int len = strlen(source);
    if(source[len - 1] == '\n')
        source[len - 1] = '\0';
    
    dest[len - 1] = '\0';    
    reverse(source, len - 1, dest);
    
    printf("\n Input: %s", source);
    printf("\nOutput: %s\n", dest);

    return (EXIT_SUCCESS);
}

void reverse(char *source, int len, char *dest)
{
    if(*source != 0)
    {
        *(dest + len - 1) = *source;
        
        reverse((char *)(source + 1), len - 1, dest);
    }    
}