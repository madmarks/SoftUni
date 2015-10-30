#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 07. Sort 3 Numbers with Nested Ifs
 * 
 * Write a program that enters 3 real numbers and prints them sorted in 
 * descending order. Use nested if statements. Don’t use arrays and 
 * the built-in sorting functionality. 
 */
int main() 
{
    float a;
    float b;
    float c;
    
    printf("Input a = ");
    scanf("%f", &a);
    printf("Input b = ");
    scanf("%f", &b);
    printf("Input c = ");
    scanf("%f", &c);
     
    printf("|   a  |   b  |   c  |     result     |\n");
    printf("| %4.1f | %4.1f | %4.1f | ", a, b, c);
    
    if(a >= b && a >= c)
    {
        printf("%4.1f %4.1f %4.1f |\n", a, b >= c ? b : c, b >= c ? c : b);
    }
    else if(b >= a && b >= c)
    {
        printf("%4.1f %4.1f %4.1f |\n", b, a >= c ? a : c, a >= c ? c : a);
    }
    else // c >= a && c >= b
    {
        printf("%4.1f %4.1f %4.1f |\n", c, a >= b ? a : b, a >= b ? b : a);
    }

    return (EXIT_SUCCESS);
}

