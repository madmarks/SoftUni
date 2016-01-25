#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 07. Average Sum
 * 
 * Write a program that finds the average of the sum of 3 numbers.
 */
int main() 
{
    double a;
    double b;
    double c;
    
    printf("Input a = ");
    scanf("%lf", &a);        

    printf("Input b = ");
    scanf("%lf", &b);
    
    printf("Input c = ");
    scanf("%lf", &c);
    
    double average = (a + b + c)/3;
    
    printf("\n|     a     |     b     |     c     |  Average  |\n");
    printf("| %lf | %lf | %lf | %lf |\n", a, b, c, average);

    return (EXIT_SUCCESS);
}

