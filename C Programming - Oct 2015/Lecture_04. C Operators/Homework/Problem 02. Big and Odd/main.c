#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 02. Big and Odd
 * 
 * Write a program that prints if the number is both greater than 20 and odd.
 */
int main() 
{
    int n;
    
    printf("Input integer number. n = ");
    scanf("%d", &n);
    
    printf("\n|    n    | Result |\n");
    printf("|%8d |    %c   |\n", n, (n>20 && abs(n%2)==1) ? '1' : '0');

    return (EXIT_SUCCESS);
}

