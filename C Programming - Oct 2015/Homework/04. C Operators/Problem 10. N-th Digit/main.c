#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 10. N-th Digit
 * 
 * Write a program that prints the n-th digit of a number (from right to left). 
 * If no such digit exists, print a dash "-".
 */
int main() 
{
    int number;
    int n;
    int remainder;
    int remainingNumber;
    int count = 0;
    
    printf("Input Number = ");
    scanf("%d", &number);
    printf("Input n = ");
    scanf("%d", &n);
    
    remainingNumber = number;    
    do
    {
        remainder = remainingNumber % 10;
        remainingNumber = (remainingNumber - remainder) / 10;
        count++;
    }while(count < n && remainingNumber != 0);
    
    printf("\n| Number |  n  | Result |\n");
    printf("|   %4d | %2d  |    %c   |\n", 
        number, n, count == n ? (0x30 + remainder): '-');

    return (EXIT_SUCCESS);
}

