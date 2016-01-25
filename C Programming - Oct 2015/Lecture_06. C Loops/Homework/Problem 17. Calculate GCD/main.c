#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 17. Calculate GCD
 * 
 * Write a program that calculates the greatest common divisor(GCD) of given two
 * integers a and b. Use the Euclidean algorithm (find it in Internet).
 */
int main() 
{
    int a;
    int b;
    int gcd;
    
    printf("Input a = ");
    scanf("%d", &a);
    printf("Input b = ");
    scanf("%d", &b);
    
    int temp;
    
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    
    printf("\n| GCD(a, b) |\n");
    printf("| %-9d |\n", abs(a));

    return (EXIT_SUCCESS);
}

