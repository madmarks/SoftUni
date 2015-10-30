#include <stdio.h>
#include <stdlib.h>

/*
 * Declare two integer variables a and b and assign them with 5 and 10 and 
 * after that exchange their values by using some programming logic.
 * Print the variable values before and after the exchange.
 */
int main() 
{
    int a = 5;
    int b = 10;
    
    printf("Before:\n");
    printf("a = %d\n", a);
    printf("b = %d\n\n", b);
    
    // Exchange two numbers without temp variable
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("After:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return (EXIT_SUCCESS);
}