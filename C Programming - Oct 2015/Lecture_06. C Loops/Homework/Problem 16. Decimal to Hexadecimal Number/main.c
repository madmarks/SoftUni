#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

/*
 * Problem 16. Decimal to Hexadecimal Number
 * 
 * Using loops write a program that converts an integer number to its 
 * hexadecimal representation. 
 * The input is entered as long. 
 * The output should be a variable of type string. 
 */
int main() 
{
    int i;
    long decimal;
    char reversedHexStr[BUFFER_LENGTH];
    reversedHexStr[0] = '\0';
    
    printf("Input decimal = ");
    scanf("%ld", &decimal);
    
    /* Flipping bits (Mirror) of an Integer */
    //unsigned int a = (int)0x12345678;
    //unsigned int b = 0;
    //i = 0;
    //for (i = 31; i > 0; --i)
    //{
    //    /* member of the ugly code club here*/
    //    b = b + ((a>>(31 - i))<<(31)>>(31 - i));
    //}
    /* endOf: Flipping bits (Mirror) of an Integer */
    
    char ch[2] = { 0x00, 0x00 };
    int remainder;      
    
    while(decimal / 16 != 0 || decimal % 16 != 0)
    {
        remainder = decimal % 16;
        
        if(0 <= remainder && remainder <= 9)
        {
            ch[0] = remainder + 0x30;
        }
        else
        {
            ch[0] = remainder + 0x37;
        }
        
        strcat(reversedHexStr, ch);
        
        decimal /= 16;
    }
    
    /* Reverse string */
    
    char *hexStr;
    int len = strlen(reversedHexStr);
    
    if(len > 0)
    {
        hexStr = malloc(len + 1);
        hexStr[len] = '\0';
        
        for(i = 0; i < len; i++)
        {
            hexStr[i] = reversedHexStr[len - 1 - i];
        }
    }
    
    /* Print result */

    int titleLen = strlen("hexadecimal");
    int rowWidth = strlen(hexStr);
    
    int numSpacesAfter = rowWidth > titleLen ? (rowWidth - titleLen)/2 : 0;
    int numSpacesBefore = numSpacesAfter;
    
    if((rowWidth > titleLen) && ((rowWidth - titleLen) % 2) != 0)
    {
        numSpacesBefore++;
    }
    
    printf("\n| %*s%s%*s |\n", numSpacesBefore, "", "hexadecimal", 
        numSpacesAfter, "");
    printf("| %*s |\n", titleLen, hexStr);
    
    free(hexStr);

    return (EXIT_SUCCESS);
}

