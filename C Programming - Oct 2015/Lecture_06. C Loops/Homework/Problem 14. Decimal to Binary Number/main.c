#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

#define BUFFER_LENGTH 200

/*
 * Problem 14. Decimal to Binary Number
 * 
 * Using loops write a program that converts an integer number to its binary 
 * representation. 
 * The input is entered as long. 
 * The output should be a variable of type string.
 */
int main() 
{
    long decimal;
    char binary[BUFFER_LENGTH];
    binary[0] = '\0';
    
    printf("Input decimal = ");
    scanf("%ld", &decimal);  
    
    int i = 0;
    int len = sizeof(long) * 8;
    
    while(((decimal >> (len - 1 - i)) & 0x1) == 0 && i < (len - 1))
    {
        i++;
    }
    
    do
    {
        if(((decimal >> (len - 1 - i)) & 0x1) == 1)
        {
            strcat(binary, "1");
        }
        else
        {
            strcat(binary, "0");
        }
        
        i++;
    }while(i < len);
    
    int titleLen = strlen("binary");
    int rowWidth = strlen(binary);
    
    int numSpacesAfter = rowWidth > titleLen ? (rowWidth - titleLen)/2 : 0;
    int numSpacesBefore = numSpacesAfter;
    
    if((rowWidth > titleLen) && ((rowWidth - titleLen) % 2) != 0)
    {
        numSpacesBefore++;
    }
    
    printf("\n| %*s%s%*s |\n", numSpacesBefore, "", "binary", 
        numSpacesAfter, "");
    printf("| %*s |\n", titleLen, binary);

    return (EXIT_SUCCESS);
}

