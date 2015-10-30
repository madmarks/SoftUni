#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 05. The Biggest of 3 Numbers
 * 
 * Write a program that finds the biggest of three numbers.
 */
int main() 
{
    float a;
    float b;
    float c;
    float biggest;
    
    printf("Input a = ");
    scanf("%f", &a);
    printf("Input b = ");
    scanf("%f", &b);
    printf("Input c = ");
    scanf("%f", &c);
    
    if(a >= b && a >= c)
    {
        biggest = a;
    }
    else if(b >= a && b >= c)
    {        
        biggest = b;
    }
    else
    {
        biggest = c;
    }
    
    printf("|   a  |   b  |   c  | biggest |\n");
    printf("| %4.1f | %4.1f | %4.1f |   %4.1f  |", a, b, c, biggest);    

    return (EXIT_SUCCESS);
}

