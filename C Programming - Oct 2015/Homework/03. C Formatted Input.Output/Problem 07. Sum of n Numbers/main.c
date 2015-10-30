#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * Problem 07. Sum of n Numbers
 * 
 * Write a program that enters a number n and after that enters 
 * more n numbers and calculates and prints their sum.
 */
int main() 
{
    int i;
    int n;
    double number;
    double sum = 0;
    
    do
    {
        printf("How many numbers sum do you want to calculate? n = ");
        scanf("%d", &n);

        if(n < 1)
        {
            printf("Error: n must be >= 1\n\n");
        }
    }while(n < 1);
    
    for(i = 1; i <= n; i++)
    {
        errno = 0;
        printf("Input number = ");
        scanf("%lf", &number);
        
        if(errno == ERANGE)
        {
            printf("Error: this number is out of range!");
            return (EXIT_FAILURE);
        }
        
        sum += number;
    }
    
    printf("sum = %lf\n", sum);

    return (EXIT_SUCCESS);
}

