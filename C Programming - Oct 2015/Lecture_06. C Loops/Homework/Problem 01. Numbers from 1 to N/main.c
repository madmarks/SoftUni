#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 1. Numbers from 1 to N
 * 
 * Write a program that enters from the console a positive integer n and 
 * prints all the numbers from 1 to n, on a single line, separated by a space.
 */
int main() 
{
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    printf("\n|  n  | output\n");
    printf("| %3d | ", n);
    
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    
    printf("\n");

    return (EXIT_SUCCESS);
}

