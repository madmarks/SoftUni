#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 08. Third Digit is 7
 * 
 * Write an expression that checks for given integer if its third digit from 
 * right-to-left is 7. Print true or false.
 */
int main() 
{
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    _Bool isThirdRightToLeftDigit7 = (n/100)%10 == 7;
    
    printf("\n|    n    | Third digit 7? |\n");
    printf("| %7d | %10s     |\n", n, isThirdRightToLeftDigit7 ? "true" : "false");

    return (EXIT_SUCCESS);
}

