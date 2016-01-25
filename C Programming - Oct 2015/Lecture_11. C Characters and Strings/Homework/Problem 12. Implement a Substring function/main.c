#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char * substr(const char *, int, int);
void error(char *);

/*
 * Problem 12. Implement a Substring function
 * 
 * Implement a function which extracts a substring from a given string by 
 * specifying the position from which to extract and the length to extract. 
 * The declaration could be as follows:
 * 
 * int substr(char * src, int position, int length);
 * 
 * ----------------------------------------------------------------------------
 *                   Input                    |          Output
 * ----------------------------------------------------------------------------
 * substr("Breaking Bad", 0, 2);              | Br
 * ----------------------------------------------------------------------------
 * substr("Maniac", 3, 3);                    | iac
 * ----------------------------------------------------------------------------
 * substr("Maniac", 3, 5);                    | iac
 * ----------------------------------------------------------------------------
 * substr("Master Yoda", 13, 5);              | (empty string)
 * ----------------------------------------------------------------------------
 */
int main() 
{
    int index;
    char * str = NULL;
    
    int variant = 0; // choose variant you want to test
    
    printf("\n Output\n");
    
    switch (variant) 
    {
        case 0:
        {
            if(NULL == (str = substr("Breaking Bad", 0, 2)))
                return;
            
            printf("%s\n", str);
            break;
        }
        case 1:
        {
            if(NULL == (str = substr("Maniac", 3, 3)))
                return;
            
            printf("%s\n", str);
            break;
        }
        case 2:
        {
            if(NULL == (str = substr("Maniac", 3, 5)))
                return;
            
            printf("%s\n", str);
            break;
        }
        case 3:
        {
            if(NULL == (str = substr("Master Yoda", 13, 5)))
                return;
            
            printf("%s\n", str);
            break;
        }
    }
    
    /* Free allocated memory */
    
    if(str)
        free(str);

    return (EXIT_SUCCESS);
}

char * substr(const char * src, int position, int length)
{
    size_t src_len = strlen(src);
    
    if(position > src_len)
        return NULL;
    
    int available_chars = src_len - position;
    int substr_len_to_print = 
        length > available_chars ? available_chars : length;
    
    char * substring = (char *)malloc(substr_len_to_print + 1);
    if(NULL == substring)
    {
        error("Error when malloc() in substr function.\n");
        return NULL;
    }
    substring[substr_len_to_print] = '\0';
    
    memcpy(substring, src + position, substr_len_to_print);    
    
    return substring;
}

void error(char *msg)
{
    if(errno != 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }
    perror(msg);
}