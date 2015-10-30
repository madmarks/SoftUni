#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#define BUFFER_LENGTH 100
#define PI 3.14159265

/*
 * Problem 03. Circle Perimeter and Area
 * 
 * Write a program that reads the radius r of a circle and prints its 
 * perimeter and area formatted with 2 digits after the decimal point.
 */
int main() 
{
    double radius;
    double perimeter;
    double area;
    char buffer[BUFFER_LENGTH];
    char *startPtr;
    char *endPtr;
    int length;
    
    printf("Input radius r of a circle: ");
    if(NULL != fgets(buffer, BUFFER_LENGTH, stdin))
    {
        /* Remove trailing newline, if any */
        length = strlen(buffer);
        if(buffer[length - 1] == '\n')
            buffer[length - 1] = '\0';        
        
        startPtr = buffer;
        errno = 0;
        radius = strtod(startPtr, &endPtr);
 
        printf("Original input: '%.*s' -> Parsed: ", 
                (int)(endPtr-startPtr), startPtr);
        
        startPtr = endPtr; // we need this when parse many numbers
        if (errno == ERANGE)
        {
            printf("range ERROR, got %f\n", radius);
            printf("strtod(...) returns errno == ERANGE\n");
            errno = 0;
            
            if (radius == 0) 
            {                
                /* ...underflow */
                printf("...underflow\n");
            } 
            else if (radius == HUGE_VAL) 
            {
                /* ...positive overflow */
                printf("...positive overflow\n");                
            } 
            else if (radius == -HUGE_VAL) 
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
        printf("%f\n", radius);
    }
    else
    {
        printf("Error! fgets(...) returns NULL.");
        return (EXIT_FAILURE);
    }
    
    printf("\nPerimeter of circle 2*PI*radius = %.2lf\n", 2*PI*radius);
    printf("\nArea of circle PI*(radius^2) = %.2lf\n", PI*radius*radius);

    return (EXIT_SUCCESS);
}

