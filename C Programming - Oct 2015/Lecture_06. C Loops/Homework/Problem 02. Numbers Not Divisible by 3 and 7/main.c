#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 2. Numbers Not Divisible by 3 and 7
 * 
 * Write a program that enters from the console a positive integer n and prints 
 * all the numbers from 1 to n not divisible by 3 and 7, on a single line, 
 * separated by a space.
 */
int main() 
{
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    printf("\n|  n  | output\n");
    printf("| %3d | ", n);
    
    int i;
    for(i = 1; i <= n; i++)
    {
        if(i%3 == 0 || i%7 == 0)
        {
            continue;
        }
        
        printf("%d ", i);
    }
    
    printf("\n");

    return (EXIT_SUCCESS);
}

