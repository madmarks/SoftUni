#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_LENGTH 100

double reverse(char *str, int *error);

/*
 * Problem 4. Reverse Number
 * 
 * Write a function that reverses the digits of a given floating-point number. 
 * The function should receive a double number and a pointer to an integer 
 * variable. In case of format error, it should set error to 1 and in case of 
 * success to 0. Declare a function prototype before defining the function.
 */
int main() 
{
    char str[BUFFER_LENGTH];
    int error;
    
    printf("Input number = ");
    scanf("%s", str);
    
    double reversed = reverse(str, &error);
    
    printf("\n|   Input  |     Output     |\n");
    
    if(error == 0)
    {
        printf("| %8s | %-14.3f |\n", str, reversed);
    }
    else
    {
        printf("| %8s | Invalid format |\n", str);
    }
    
    return (EXIT_SUCCESS);
}

double reverse(char *str, int *error)
{   
    *error = 1;
    int length = strlen(str);
    
    if(length > 0)
    {
        char *strReversed = malloc(length + 1);
        strReversed[length] = '\0';
        
        int i;
        for(i = 0; i < length; i++)
        {
            strReversed[i] = str[length - 1 - i];
        }
        
        char *endPtr;
        errno = 0;
        double d = strtod(strReversed, &endPtr);
        
        if(errno == 0 && strReversed != endPtr)
        {
            *error = 0;
            return d;
        }
    }
   
    return 0.0;
}