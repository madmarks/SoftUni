#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 04. Multiplication Sign
 * 
 * Write a program that shows the sign (+, - or 0) of the product of three real 
 * numbers, without calculating it. Use a sequence of if operators.
 */
int main() 
{
    float a;
    float b;
    float c;
    char result;
    
    printf("Input a = ");
    scanf("%f", &a);
    printf("Input b = ");
    scanf("%f", &b);
    printf("Input c = ");
    scanf("%f", &c);
    
    if(a == 0 || b == 0 || c == 0)
    {
        result = '0';
    }
    else
    {
        if(a > 0)
        {
            if((b > 0 && c > 0) || (b < 0 && c < 0))
            {
                result = '+';
            }
            else
            {
                result = '-';
            }
        }
        else // a < 0
        {
            if((b > 0 && c > 0) || (b < 0 && c < 0))
            {
                result = '-';
            }
            else
            {
                result = '+';
            }
        }
    }
    
    printf("|   a  |   b  |   c  | result |\n");
    printf("| %4.1f | %4.1f | %4.1f |    %c   |", a, b, c, result);
    
    return (EXIT_SUCCESS);
}

