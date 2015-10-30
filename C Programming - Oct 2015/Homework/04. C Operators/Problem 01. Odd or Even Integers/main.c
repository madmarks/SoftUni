#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 01. Odd or Even Integers
 * 
 * Write an expression that checks if given integer is odd or even.
 */
int main() 
{
    int n;
    
    printf("Input integer number. n = ");
    scanf("%d", &n);
    
    printf("\n|    n    | Odd? |\n");
    printf("|%8d |   %c  |\n", n, abs(n%2)==1 ? '1' : '0');
    
    return (EXIT_SUCCESS);
}

