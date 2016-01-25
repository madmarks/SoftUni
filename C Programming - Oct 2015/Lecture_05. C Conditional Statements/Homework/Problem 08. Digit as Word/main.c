#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <limits.h>

#define BUFFER_LENGTH 100

/*
 * Problem 08. Digit as Word
 * 
 * Write a program that asks for a digit (0-9), and depending on the input,
 * shows the digit as a word (in English). Print "not a digit" in case of 
 * invalid inut. Use a switch statement.
 */
int main() 
{
    char buffer[BUFFER_LENGTH];
    char *startPtr;
    char *endPtr;
    long int digit;
    
    printf("Input digit: ");
    if(NULL != fgets(buffer, BUFFER_LENGTH, stdin))
    {
        int length = strlen(buffer);
        
        /* Remove trailing newline, if any */
        if(buffer[length - 1] == '\n')
            buffer[length - 1] = '\0';
        
        startPtr = buffer;
        errno = 0;
        digit = strtol(startPtr, &endPtr, 10);
        
        printf("Original input: '%.*s' -> Parsed: ", 
            (int)(endPtr-startPtr), startPtr);
        
        if (errno == ERANGE)
        {
            printf("range ERROR, got %li\n", digit);
            printf("strtol(...) returns errno == ERANGE\n");
            errno = 0;
            
            if (digit == LONG_MIN) 
            {                
                /* ...underflow */
                printf("...underflow\n");
            } 
            else if (digit == LONG_MAX) 
            {
                /* ...positive overflow */
                printf("...positive overflow\n");                
            } 
            else 
            {                
                /* ...unknown range error? */
                printf("...unknown range error? n");
            }
            
            return (EXIT_FAILURE);        
        }
        printf("%li\n\n", digit);
    }
    else
    {
        printf("Error. Wrong input.");
        return (EXIT_FAILURE);
    }
    
    printf("|   d   |    result   |\n");
    printf("| %5s ", buffer);
    
    switch(digit)
    {
        case 0:
            printf("| %-11s |\n", "zero");
            break;
        case 1:
            printf("| %-11s |\n", "one");
            break;
        case 2:
            printf("| %-11s |\n", "two");
            break;
        case 3:
            printf("| %-11s |\n", "three");
            break;
        case 4:
            printf("| %-11s |\n", "four");
            break;
        case 5:
            printf("| %-11s |\n", "five");
            break;
        case 6:
            printf("| %-11s |\n", "six");
            break;
        case 7:
            printf("| %-11s |\n", "seven");
            break;
        case 8:
            printf("| %-11s |\n", "eight");
            break;
        case 9:
            printf("| %-11s |\n", "nine");
            break;
        default:
            printf("| %-11s |\n", "not a digit");
    }

    return (EXIT_SUCCESS);
}

