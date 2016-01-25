#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 06. Numbers from 1 to n
 * 
 * Write a program that reads an integer number n from the console and 
 * prints all the numbers in the interval [1..n], each on a single line.
 */
int main() 
{
    int i;
    unsigned short n;
    
    printf("Input an integer number n = ");
    scanf("%hu", &n);
    
    if(n <= 0)
    {
        printf("n must be positive number greater than 0\n");
    }
    
    for(i = 1; i <= n; i++)
    {
        printf("%hu\n", i);
    }

    return (EXIT_SUCCESS);
}

