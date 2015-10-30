#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define BUFFER_LENGTH 150

/*
 * Problem 01. Sum of 3 Numbers
 * 
 * Write a program that reads 3 real numbers from the console and 
 * prints their sum.
 */
int main()
{
    int counter;
    double sum;
    char buffer[BUFFER_LENGTH];
    float parsedFloatNumber;
    char *startPtr;
    char *endPtr;
    int numbersToRead = 3;
    
    do
    {   
        counter = 0;
        sum = 0.0;
        printf("Input 3 float numbers (a b c): ");
        
        if(NULL != fgets(buffer, BUFFER_LENGTH, stdin))
        {
            startPtr = buffer;
            
            do
            {
                errno = 0;
                parsedFloatNumber = strtof(startPtr, &endPtr);
                if(errno == 0)
                {
                    if(startPtr != endPtr)
                    {
                        sum += parsedFloatNumber;
                        startPtr = endPtr;
                        endPtr = NULL;
                        counter++;
                    }
                }
                else if (errno == ERANGE) 
                {
                    if (parsedFloatNumber == 0) 
                    {
                        /*...underflow */
                    } else if (parsedFloatNumber == HUGE_VAL) 
                    {
                        /*...positive overflow */
                    } else if (parsedFloatNumber == -HUGE_VAL) 
                    {
                        /*...negative overflow */
                    } else 
                    {
                        /*...unknown range error? */
                    }
                }
            }while(startPtr != endPtr);
        }
    }while(counter != numbersToRead);
    
    printf("Sum(a+b+c) = %.10lf", sum);
    
    return (EXIT_SUCCESS);
}

