#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 06. The Biggest of Five Numbers
 * 
 * Write a program that finds the biggest of five numbers by using only 
 * five if statements.
 */
int main() 
{
    float a;
    float b;
    float c;
    float d;
    float e;
    float biggest;
    
    printf("Input a = ");
    scanf("%f", &a);
    printf("Input b = ");
    scanf("%f", &b);
    printf("Input c = ");
    scanf("%f", &c);
    printf("Input d = ");
    scanf("%f", &d);
    printf("Input e = ");
    scanf("%f", &e);
    
    if(a >= b && a >= c && a >= d && a >= e)
    {
        biggest = a;
    }
    else if(b >= a && b >= c && b >= d && b >= e)
    {        
        biggest = b;
    }
    else if(c >= a && c >= b && c >= d && c >= e)
    {
        biggest = c;
    }
    else if(d >= a && d >= b && d >= c && d >= e)
    {
        biggest = d;
    }
    else
    {
        biggest = e;
    }
    
    printf("|   a   |   b   |   c   |   d   |   e   |  biggest |\n");
    printf("| %5.1f | %5.1f | %5.1f | %5.1f | %5.1f |   %5.1f  |", 
        a, b, c, d, e, biggest);

    return (EXIT_SUCCESS);
}

