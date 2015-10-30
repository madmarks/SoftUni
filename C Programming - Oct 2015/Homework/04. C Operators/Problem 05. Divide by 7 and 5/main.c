#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 05. Divide by 7 and 5
 * 
 * Write a Boolean expression that checks for given integer if it can be 
 * divided (without remainder) by 7 and 5 in the same time.
 */
int main() 
{
    int n;
    
    printf("Input integer number. n = ");
    scanf("%d", &n);
    
    _Bool isDivideble = n%7==0 && n%5==0;
    
    printf("\n|    n    | Divided by 7 and 5? |\n");
    printf("|%8d |          %c          |\n", n, isDivideble ? '1' : '0');

    return (EXIT_SUCCESS);
}

