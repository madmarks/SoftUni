#include <stdio.h>
#include <stdlib.h>

/*
 * Declare an integer variable and assign it with 
 * the value 254 in hexadecimal format (0x##). Use a calculator online 
 * to find its hexadecimal representation. 
 * Print the variable and ensure that the result is "254".
 */
int main() 
{
    int a = 0xFE;
     
    printf("a = %d (DECIMAL)\n", a);
    printf("a = 0x%X (HEXADECIMAL)\n", a);

    return (EXIT_SUCCESS);
}

