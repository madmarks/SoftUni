#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

/*
 * Problem 01. Swap numbers
 * 
 * Implement a function which takes as input two numbers and swaps their
 * values. The declaration of the function should be something like:
 * 
 * void swap(int *first, int *second)
 */
int main() 
{
    int a;
    int b;
    
    printf("Input a = ");
    scanf("%d", &a);
    printf("Input b = ");
    scanf("%d", &b);
    
    swap(&a, &b);
    
    printf("\na = %d\n", a);
    printf("b = %d\n", b);

    return (EXIT_SUCCESS);
}

void swap(int *first, int *second)
{
    int tmp;
    
    tmp = *first;
    *first = *second;
    *second = tmp;
}