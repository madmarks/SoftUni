#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
void str_tolower(char *);
int how_many_substrings(char *, char *);

/*
 * Problem 04. Count Substring Occurrences
 * 
 * Write a program to find how many times a given string appears in a given 
 * text as substring. The text is given at the first input line. The search 
 * string is given at the second input line. The output is an integer number. 
 * Please ignore the character casing. 
 * Overlapping between occurrences is allowed. 
 * 
 *                         Input                             |     Output
 * ----------------------------------------------------------------------------
 * Welcome to the Software University (SoftUni)! Welcome to  | 4
 * programming. Programming is wellness for developers, said |
 * Maxwell.                                                  | 
 * wel                                                       | 
 * ---------------------------------------------------------------------------- 
 * aaaaaa                                                    | 5
 * aa                                                        | 
 * ----------------------------------------------------------------------------
 * ababa caba                                                | 3
 * aba                                                       | 
 * ----------------------------------------------------------------------------
 * Welcome to SoftUni                                        | 0
 * Java                                                      | 
 * ----------------------------------------------------------------------------
 */
int main()
{
    size_t len = BUFFER_LENGTH; // initial size of buffer
    ssize_t read;
    
    errno = 0;
    char *str = (char *)malloc(len);
    if(NULL == str)
    {
        error("Not enough memory!");
        return (EXIT_FAILURE);
    }
    
    errno = 0;
    char *substr = (char *)malloc(len);
    if(NULL == substr)
    {
        error("Not enough memory!");
        return (EXIT_FAILURE);
    }
    
    printf("  Input text:");
    if((read = getline(&str, &len, stdin)) != -1)
    {
        if(read > 0 && str[read - 1] == '\n')
        {
            str[read - 1] = '\0';
            read--;
        }
    }
    
    printf("Input string:");
    if((read = getline(&substr, &len, stdin)) != -1)
    {
        if(read > 0 && substr[read - 1] == '\n')
        {
            substr[read - 1] = '\0';
            read--;
        }
    }
    
    str_tolower(str);
    str_tolower(substr);
    
    printf("\n Output\n");
    printf("%d\n", how_many_substrings(str, substr));

    free(substr);
    free(str);
    
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

void str_tolower(char *str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

int how_many_substrings(char *str, char *substr)
{
    char *ptr = str;
    int count = 0;
    
    while(NULL != (ptr = strstr(ptr, substr)))
    {
        ptr++;
        count++;
    }  
    
    return count;
}