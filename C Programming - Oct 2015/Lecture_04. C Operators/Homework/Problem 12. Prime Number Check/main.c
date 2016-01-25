#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
 * Problem 12. Prime Number Check
 * 
 * Write an expression that checks if given positive integer number n (n ≤ 100) 
 * is prime (i.e. it is divisible without remainder only to itself and 1). 
 * Print true or false.
 */
int main() {
    int n;
    _Bool isPrime = false;

    printf("Input n = ");
    scanf("%d", &n);

    if (n > 1) 
    {
        isPrime = true;
        
        int i;
        int upperLimitOfChecks = (int)sqrt(n) + 1;
        
        for (i = 2; i < upperLimitOfChecks; i++) 
        {
            if (n % i == 0) 
            {
                isPrime = false;
                break;
            }
        }
    }

    printf("\n|  n  |  Prime? |\n");
    printf("| %3d |  %5s  |\n", n, isPrime ? "true" : "false");

    return (EXIT_SUCCESS);
}

