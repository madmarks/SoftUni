#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void printFibonachiNumbers(int const n)
{
    int i;
    uint64_t fibNminus2 = 0;
    uint64_t fibNminus1 = 1;
    uint64_t fibN;
    
    printf("%"PRIu64" ", fibNminus2);
    if((n - 1) == 0)
        return;
    
    printf("%"PRIu64" ", fibNminus1);
    if((n - 1) == 1)
        return;
    
    for(i = 2; i < n; i++)
    {
        fibN = fibNminus1 + fibNminus2;
        fibNminus2 = fibNminus1;
        fibNminus1 = fibN;
        printf("%"PRIu64" ", fibN);
    }
}

/*
 * Problem 08. Fibonacci Numbers
 * 
 * Write a program that reads a number n and prints on the console the first n 
 * members of the Fibonacci sequence (at a single line, separated by spaces) :
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
 */
int main() 
{
    int i;
    int n;
    
    do
    {
        printf("Input how many members of Fibonacci sequence do you want to view.");
        printf(" n = ");
        scanf("%d", &n);
    
        if(n < 1)
        {
            printf("Error: n must be >= 1\n\n");
        }
    }while(n < 1);
    
    printf("\n");
    printFibonachiNumbers(n);
    printf("\n");

    return (EXIT_SUCCESS);
}

