#include <stdio.h>
#include <stdlib.h>

int get_max(int a, int b);

/*
 * Problem 1. Bigger Number
 * 
 * Write a function get_max() with two parameters that returns the bigger of 
 * two integers. Write a program that reads 2 integers from the console and 
 * prints the largest of them using the function get_max(). 
 * Declare a function prototype before defining the function.
 */
int main() 
{
    int a;
    int b;
    
    printf("Input a = ");
    scanf("%i", &a);
    printf("Input b = ");
    scanf("%i", &b);
    
    printf("\n|    a   |    b   | Bigger |\n");
    printf("| %6i | %6i | %6i |\n", a, b, get_max(a, b));

    return (EXIT_SUCCESS);
}

int get_max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    
    return b;
}