#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 01. Exchange If Greater
 * 
 * Write an if-statement that takes two integer variables a and b and exchanges
 * their values if the first one is greater than the second one. 
 * As a result print the values a and b, separated by a space.
 */
int main() 
{
    float a;
    float b;
    
    printf("Input a = ");
    scanf("%f", &a);
    printf("Input b = ");
    scanf("%f", &b);   
    
    printf("|  a  |  b  |  result  |\n");
    printf("| %.1f | %.1f | %.1f  %.1f |", a, b, (a > b)? b:a, (a > b)? a:b);

    return (EXIT_SUCCESS);
}

