#include <stdio.h>
#include <stdlib.h>

char *lastDigitAsWord(int a);

/*
 * Problem 2. Last Digit of Number
 * 
 * Write a function that returns the last digit of a given integer as 
 * an English word. Test the function with different input values. 
 * Ensure you name the function properly. 
 * Declare a function prototype before defining the function.
 */
int main() 
{
    int a;
    
    printf("Input n = ");
    scanf("%i", &a);
    
    printf("\n|  Input | Output |\n");
    printf("| %6i | %6s |\n", a, lastDigitAsWord(a));

    return (EXIT_SUCCESS);
}

char *lastDigitAsWord(int a)
{
    int lastDigit = a % 10;
    
    switch(lastDigit)
    {
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }    
}