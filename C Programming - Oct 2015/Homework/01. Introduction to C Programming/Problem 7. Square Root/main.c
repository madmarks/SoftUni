#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sqrt_mvp(double x);

/*
 * Problem 7. Square Root
 * 
 * Create a console application that calculates and prints 
 * the square root of the number 12345.
 * 
 * Extra: Modify your program to read the number from the console. 
 * Use the scanf() function.
 */
int main() 
{
    double number;
    
    printf("Input number: ");
    scanf("%lf", &number);
    
    //double res = sqrt(number);
    
    printf("SQRT(%.3lf) = %.7lf\n", number, sqrt(number));
    printf("SQRT(%.3lf) = %.7lf\n", number, sqrt_mvp(number));

    return (EXIT_SUCCESS);
}

/* http://stackoverflow.com/questions/
 * 19611198/finding-square-root-without-using-sqrt-function
 */
double sqrt_mvp(double x) 
{
    if (x <= 0)
        return 0;          // if negative number throw an exception?
    
    int exp = 0;
    x = frexp(x, &exp);    // extract binary exponent from x
    
    if (exp & 1)           // we want exponent to be even
    {      
        exp--;
        x *= 2;
    }
    double y = (1+x)/2;    // first approximation
    double z = 0;
    
    while (y != z)         // yes, we CAN compare doubles here!
    {    
        z = y;
        y = (y + x/y) / 2;
    }
    
    return ldexp(y, exp/2); // multiply answer by 2^(exp/2)
}