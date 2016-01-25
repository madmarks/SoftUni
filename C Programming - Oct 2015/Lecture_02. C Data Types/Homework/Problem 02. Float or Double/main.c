#include <stdio.h>
#include <stdlib.h>

/*
 * Which of the following values can be assigned to a variable of type 
 * float and which to a variable of type double: 34.567839023, 12.345, 
 * 8923.1234857, 3456.091? Write a program to assign the numbers in 
 * variables and print them to ensure no precision is lost.
 */
int main() 
{
    double a = 34.567839023;
    float b = 12.345f;
    double c = 8923.1234857;
    double d = 3456.091;
    
    printf("a = %.10lf\n", a);
    printf("b = %f\n", b);
    printf("c = %.8lf\n", c);
    printf("d = %lf\n", d);
    
    return (EXIT_SUCCESS);
}

