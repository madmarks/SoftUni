#include <stdio.h>
#include <stdlib.h>

size_t strlen_mine(const char *);

/*
 * Problem 10. Implement a String Length function
 * 
 * The standard C function size_t strlen(const char *s) returns the size of 
 * the input string. Try implementing it yourself. Think about how strings are 
 * represented in C in order to calculate their length.
 * 
 * ----------------------------------------------------------------------------
 *                   Input                    |          Output
 * ----------------------------------------------------------------------------
 * strlen("Soft");                            | 4
 * ----------------------------------------------------------------------------
 * strlen("SoftUni");                         | 7
 * ----------------------------------------------------------------------------
 * char buffer[10] =                          | 1
 *     { 'C', '\0', 'B', 'a', 'b', 'y'};      |
 *                                            |
 * strlen(buffer);                            |
 * ----------------------------------------------------------------------------
 * char * buffer =                            | 4
 *     { 'D', 'e', 'r', 'p'};                 |
 *                                            |
 * strlen(buffer);                            |
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
            printf("%zd\n", strlen_mine("Soft")); // %zd -> decimal size_t
            break;
        }
        case 1:
        {
            printf("%zd\n", strlen_mine("SoftUni"));
            break;
        }
        case 2:
        {
            char buffer[10] = { 'C', '\0', 'B', 'a', 'b', 'y'};
            printf("%zd\n", strlen_mine(buffer));
            break;
        }
        case 3:
        {
            char buffer[] = { 'D', 'e', 'r', 'p', '\0' };
            printf("%zd\n", strlen_mine(buffer));
            break;
        }
    }

    return (EXIT_SUCCESS);
}

size_t strlen_mine(const char *str)
{
    size_t count = 0;
    const char *ptr = str;
    
    while(*ptr)
    {
        count++;
        ptr++;
    }
    
    return count;
}