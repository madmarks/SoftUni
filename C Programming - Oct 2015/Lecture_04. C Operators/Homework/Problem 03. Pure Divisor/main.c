#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 03. Pure Divisor
 * 
 * Write a program that prints if a number is divided by 9, 11 or 
 * 13 without remainder.
 */
int main() 
{
    int n;
    
    printf("Input integer number. n = ");
    scanf("%d", &n);
    
    _Bool isDivideble = n%9==0 || n%11==0 || n%13==0;
    
    printf("\n|    n    | Result |\n");
    printf("|%8d |    %c   |\n", n, isDivideble ? '1' : '0');

    return (EXIT_SUCCESS);
}

