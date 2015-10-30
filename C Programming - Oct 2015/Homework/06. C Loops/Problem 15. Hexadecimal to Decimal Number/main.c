#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

/*
 * Problem 15. Hexadecimal to Decimal Number
 * 
 * Using loops write a program that converts a hexadecimal integer number to its 
 * decimal form. 
 * The input is entered as string. 
 * The output should be a variable of type long.
 */
int main() 
{
    char hexadecimal[BUFFER_LENGTH];
    long decimal = 0;
    
    printf("Input hexadecimal = ");
    scanf("%s", hexadecimal);
    
    int len = strlen(hexadecimal);
    
    int i;
    char ch;
    for(i = 0; i < len; i++)
    {
        ch = hexadecimal[i];
        
        if('0' <= ch && ch <= '9')
        {
            decimal = (decimal << 4) ^ (ch - 0x30);
        }
        else if('a' <= ch && ch <= 'f')
        {
            decimal = (decimal << 4) ^ (ch - 0x57);
        }
        else if('A' <= ch && ch <= 'F')
        {
            decimal = (decimal << 4) ^ (ch - 0x37);
        }
        else
        {
            break;
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