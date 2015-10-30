/* 
 * File:   main.c
 * Author: bruteforcer
 *
 * Created on October 20, 2015, 2:12 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 11. Random Numbers in Given Range
 * 
 * Write a program that enters 3 integers n, min and max (min <= max) and 
 * prints n random numbers in the range [min...max]. 
 */
int main() {
    int n;
    int min;
    int max;
    
    printf("Input n = ");
    scanf("%d", &n);
    printf("Input min = ");
    scanf("%d", &min);
    printf("Input max = ");
    scanf("%d", &max);
    
    printf("\n|  n  |   min   |   max   |  random numbers\n");
    printf("| %3d | %7d | %7d | ", n, min, max);
    
    int i, val;
    for(i = 0; i < n; i++)
    {
        do
        {
            // The srand() function sets its argument as the seed for a new 
            // sequence of pseudo-random integers to be returned by rand().
            srand(time(NULL) + i);
            val = min + rand() % (max - min + 1);
            
            if(min <= val && val <= max)
            {
                printf("%d ", val);
            }
        
        }while(val < min || val > max);
    }
    printf("\n");

    return (EXIT_SUCCESS);
}