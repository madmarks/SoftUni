#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

/*
 * Problem 18. Trailing Zeroes in N!
 * 
 * Write a program that calculates with how many zeroes the factorial of a given
 * number n has at its end. Your program should work well for very big numbers, 
 * e.g. n=100000. 
 */
int main() 
{
    int n;
    int count = 0;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    /* General method to find the trailing zeros in factorial, 
     * no matter what factorial they give you.
     * 
     *  - Take the number that you've been given the factorial of. 
     *  - Divide by 5; if you get a decimal, truncate to a whole number.
     *  - Divide by 5^2 = 25; if you get a decimal, truncate to a whole number.
     *  - Divide by 5^3 = 125; if you get a decimal, truncate to a whole number.
     *  - Continue with ever-higher powers of 5, until your division results in 
     *    a number less than 1. Once the division is less than 1, stop.
     *  - Sum all the whole numbers you got in your divisions. This is the 
     *    number of trailing zeroes.
     */
    int i;
    for ( i = 5; n/i >= 1; i *= 5 )
    {
        count  +=  n / i;
    }
 
    /* Print result */
    
    char numZeroesStr[BUFFER_LENGTH];
    sprintf(numZeroesStr, "%d", count);

    int titleLen = strlen("trailing zeroes of n!");
    int rowWidth = strlen(numZeroesStr);
    
    int numSpacesAfter = rowWidth > titleLen ? (rowWidth - titleLen)/2 : 0;
    int numSpacesBefore = numSpacesAfter;
    
    if((rowWidth > titleLen) && ((rowWidth - titleLen) % 2) != 0)
    {
        numSpacesBefore++;
    }
    
    printf("\n| %*s%s%*s |\n", numSpacesBefore, "", "trailing zeroes of n!", 
        numSpacesAfter, "");
    printf("| %*s |\n", titleLen, numZeroesStr);

    return (EXIT_SUCCESS);
}

