#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 5. Calculate 1 + 1!/X + 2!/X^2 + ... + N!/X^N
 * 
 * Write a program that, for a given two integer numbers n and x, calculates 
 * the sum S = 1 + 1!/x + 2!/x^2 + ... + n!/x^n. Use only one loop. 
 * Print the result with 5 digits after the decimal point.
 */
int main() 
{
    int n;
    int x;
    unsigned long long factorial = 1;
    long long productX = 1;
    long double s = 1;
    
    printf("Input n = ");
    scanf("%d", &n);
    printf("Input x = ");
    scanf("%d", &x);
    
    int i;
    for(i = 1; i <= n; i++)
    {
        factorial *= i;
        productX *= x;
        s += (long double)factorial/productX;
    }
    
    printf("\n|   n   |   x   |      s     |\n");
    printf("| %5d | %5d | %10.5Lf |\n", n, x, s);

    return (EXIT_SUCCESS);
}

