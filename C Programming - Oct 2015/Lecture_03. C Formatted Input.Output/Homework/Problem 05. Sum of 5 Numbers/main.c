#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#define BUFFER_LENGTH 200

/*
 * Problem 05. Sum of 5 Numbers
 * 
 * Write a program that enters 5 numbers (given in a single line, separated by 
 * a space), calculates and prints their sum.
 */
int main() 
{
    double numbers[5];
    char buffer[BUFFER_LENGTH];
    char *startPtr;
    char *endPtr;
    int length;
    int i;
    
    printf("Input 5 numbers in a single line, separated by a space: ");
    if(NULL != fgets(buffer, BUFFER_LENGTH, stdin))
    {
        /* Remove trailing newline, if any */
        length = strlen(buffer);
        if(buffer[length - 1] == '\n')
            buffer[length - 1] = '\0';        
        
        startPtr = buffer;
        
        for(i = 0; i < 5; i++)
        {
            errno = 0;
            numbers[i] = strtod(startPtr, &endPtr);
            
            if(startPtr == endPtr)
            {
                printf("Error: insufficient numbers.\n");
                return (EXIT_FAILURE);
            }
 
            printf("Original input: '%.*s' -> Parsed: ", 
                    (int)(endPtr-startPtr), startPtr);
            
            startPtr = endPtr; // we need this when parse many numbers
            if (errno == ERANGE)
            {
                printf("range ERROR, got %f\n", numbers[i]);
                printf("strtod(...) returns errno == ERANGE\n");
                errno = 0;

                if (numbers[i] == 0) 
                {                
                    /* ...underflow */
                    printf("...underflow\n");
                } 
                else if (numbers[i] == HUGE_VAL) 
                {
                    /* ...positive overflow */
                    printf("...positive overflow\n");                
                } 
                else if (numbers[i] == -HUGE_VAL) 
                {                
                    /* ...negative overflow */
                    printf("...negative overflow\n");
                } 
                else 
                {                
                    /* ...unknown range error? */
                    printf("...unknown range error? n");
                }

                return (EXIT_FAILURE);        
            }
            printf("%f\n", numbers[i]);
        }
    }
    else
    {
        printf("Error! fgets(...) returns NULL.");
        return (EXIT_FAILURE);
    }
    
    double sum = 0;
    for(i = 0; i < 5; i++)
    {
        sum += numbers[i];
    }
    
    printf("Sum = %.2lf", sum);

    return (EXIT_SUCCESS);
}

