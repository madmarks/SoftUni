#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strncat_mine(char *, const char *, size_t);

/*
 * Problem 08. Implement a String Concatenation Function
 * 
 * The standard C function strncat(char *dest, const char *src, size_t n)
 * concatenates the strings located in the src and the dest buffer into the 
 * dest buffer. The variable n shows the length from the src string to be 
 * concatenated. Try implementing that function yourself. Think about how you 
 * can get the length of the two strings.
 * 
 * ----------------------------------------------------------------------------
 *                   Input                    |          Output
 * ----------------------------------------------------------------------------
 * char buffer[10] = "Soft";                  | SoftUni
 * strncat(buffer, "Uni", 7)                  | 
 * ----------------------------------------------------------------------------
 * char buffer[5] = "Soft";                   | Segmentation Fault. Think why
 * strncat(buffer, "are University", 15)      | 
 * ----------------------------------------------------------------------------
 * char buffer[10] = "C";                     | C is cool
 * strncat(buffer, " is cool", 8)             |
 * ----------------------------------------------------------------------------
 * char *buffer = "C";                        | Segmentation Fault. Think why
 * strncat(buffer, " is cool", 8)             | 
 * ----------------------------------------------------------------------------
 */
int main() 
{
    int variant = 0; // choose variant you want to test
    
    switch (variant) 
    {
        case 0:
        {
            char buffer_1[10] = "Soft";
            strncat_mine(buffer_1, "Uni", 7);
            printf("%s\n", buffer_1);
            break;
        }
        case 1:
        {
            char buffer_2[5] = "Soft";
            strncat_mine(buffer_2, "ware University", 15);
            printf("%s\n", buffer_2);
            break;
        }
        case 2:
        {
            char buffer_3[10] = "C";
            strncat_mine(buffer_3, " is cool", 8);
            printf("%s\n", buffer_3);
            break;
        }
        case 3:
        {
            char *buffer_4 = "C";
            strncat_mine(buffer_4, " is cool", 8);
            printf("%s\n", buffer_4);
            break;
        }
    }

    return (EXIT_SUCCESS);
}

char *strncat_mine(char *dest, const char *src, size_t n) 
{
    size_t dest_len = strlen(dest);

    size_t i;
    for (i = 0; (i < n) && (src[i] != 0); i++) 
    {
        dest[dest_len + i] = src[i];
    }
    
    dest[dest_len + i] = '\0';

    return dest;
}