#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 13. Trapezoids
 * 
 * Write an expression that calculates trapezoid's area by given 
 * sides a and b and height h.
 */
int main() 
{
    double a;
    double b;
    double h;
    
    printf("Input a = ");
    scanf("%lf", &a);        

    printf("Input b = ");
    scanf("%lf", &b);
    
    printf("Input h = ");
    scanf("%lf", &h);
    
    double area = ((a + b)*h)/2;
    
    printf("\n|   a   |   b   |    h   |   area   |\n");
    printf("| %.3lf | %.3lf | %.3lf |   %.2lf  |\n", a, b, h, area);

    return (EXIT_SUCCESS);
}

