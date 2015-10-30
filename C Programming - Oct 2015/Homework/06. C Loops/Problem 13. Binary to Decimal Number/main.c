#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

/*
 * Problem 13. Binary to Decimal Number
 * 
 * Using loops write a program that converts a binary integer number to its 
 * decimal form. 
 * The input is entered as string. 
 * The output should be a variable of type long.
 */
int main() 
{
    char binary[BUFFER_LENGTH];
    long decimal = 0;
    
    printf("Input binary = ");
    scanf("%s", binary);
    
    int len = strlen(binary);
    
    int i;
    for(i = 0; i < len; i++)
    {
        if(binary[len - 1 - i] == '1')
        {
            decimal ^= 1 << i;
        }
    }
    
    /* Print result */
    
    char decimalStr[BUFFER_LENGTH];
    sprintf(decimalStr, "%ld", decimal);
    
    int titleLen = strlen("decimal");
    int rowWidth = strlen(decimalStr);
    
    int numSpacesAfter = rowWidth > titleLen ? (rowWidth - titleLen)/2 : 0;
    int numSpacesBefore = numSpacesAfter;
    
    if((rowWidth > titleLen) && ((rowWidth - titleLen) % 2) != 0)
    {
        numSpacesBefore++;
    }
    
    printf("\n| %*s%s%*s |\n", numSpacesBefore, "", "decimal", 
        numSpacesAfter, "");
    printf("| %*s |\n", titleLen, decimalStr);

    return (EXIT_SUCCESS);
}

