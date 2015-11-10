#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsearch(char *, char *);

/*
 * Problem 11. Implement a String Search function
 * 
 * Implement a function which checks whether a string appears as a substring in 
 * another string. It should return 1 if the string occurs and 0 if it does not. 
 * Its declaration could be:
 * 
 * int strsearch(char * src, char * substr);
 * 
 * ----------------------------------------------------------------------------
 *                   Input                    |          Output
 * ----------------------------------------------------------------------------
 * strsearch("SoftUni", "Soft");              | 1
 * ----------------------------------------------------------------------------
 * strsearch("Hard Rock", "Rock");            | 1
 * ----------------------------------------------------------------------------
 * strsearch("Ananas", "nasa");               | 0
 * ----------------------------------------------------------------------------
 */
int main() 
{
    int variant = 0; // choose variant you want to test
    
    printf("\n Output\n");
    
    switch (variant) 
    {
        case 0:
        {
            printf("%d\n", strsearch("SoftUni", "Soft"));
            break;
        }
        case 1:
        {
            printf("%d\n", strsearch("Hard Rock", "Rock"));
            break;
        }
        case 2:
        {
            printf("%d\n", strsearch("Ananas", "nasa"));
            break;
        }
    }

    return (EXIT_SUCCESS);
}

int strsearch(char * src, char * substr)
{
    size_t src_len = strlen(src);
    size_t substr_len = strlen(substr);
    
    size_t i, j;
    for(i = 0; i < src_len; i++)
    {
        for(j = 0; j < substr_len; j++)
        {
            if(src[i + j] != substr[j])
            {
                break;
            }
        }
        
        if(j == substr_len)
            return 1;
    }
    
    return 0;
}