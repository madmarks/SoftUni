#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 09. Four-Digit Number
 * 
 * Write a program that takes as input a four-digit number in format 
 * abcd (e.g. 2011) and performs the following:
 *   * Calculates the sum of the digits (in our example 2+0+1+1=4).
 *   * Prints on the console the number in reversed order: dcba (in our example 1102).
 *   * Puts the last digit in the first position: dabc (in our example 1201).
 *   * Exchanges the second and the third digits: acbd (in our example 2101).
 *   
 * The number has always exactly 4 digits and cannot start with 0.
 */
int main() 
{
    int n;
    int digits[4];
    
    printf("Input n = ");
    scanf("%d", &n);
    
    digits[0] = n % 10;
    digits[1] = (n/10) % 10;
    digits[2] = (n/100) % 10;
    digits[3] = (n/1000) % 10;
    
    int sumOfDigits = digits[3] + digits[2] + digits[1] + digits[0];
    int reversed = digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3];
    int lastDigitInFront = digits[0]*1000 + n/10;
    int secondAndThirdDigitsExchanged = 
        digits[3]*1000 + digits[1]*100 + digits[2]*10 + digits[0];
    
    printf("\n|   n  | sum of digits | reversed | last digit | second and third |\n");
    printf("|      |               |          |  in front  | digits exchanged |\n");
    printf("| %4d |       %2d      |   %4d   |    %4d    |       %4d       |\n", n, 
        sumOfDigits, reversed, lastDigitInFront, secondAndThirdDigitsExchanged);

    return (EXIT_SUCCESS);
}

