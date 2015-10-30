#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void print(int);

/*
 * Problem 04. Print Integer Address
 * 
 * Write a function which takes as input an integer and prints the address of 
 * it in the memory. 
 * 
 * Try printing the address of the integer in the function and in the main 
 * function. What is the difference and why
 * 
 * Input
 * print(5)
 * 
 * Output
 * 0x2686780
 * (The output varies depending on the address on your computer)
 */
int main() 
{
    int x = 5;
    printf("Address of variable 'x' inside of 'main' function : "
            "0x%0*" PRIXPTR "\n", (int)(2 * sizeof(uintptr_t)), (uintptr_t)&x);
    
    print(x);

    printf("\nThe Call-By-Value method of passing arguments to a function ");
    printf("copies the actual value of an\nargument into the formal parameter");
    printf(" of the function.\n");
    
    printf("\nAddresses of 'x' inside of 'main' function and 'y' inside of ");
    printf("'print' function are different\nbecause when function print() is ");
    printf("invoked, the value of 'x' gets copied onto 'y'.\n");

    return (EXIT_SUCCESS);
}

void print(int y)
{
    printf("Address of variable 'y' inside of 'print' function: "
            "0x%0*" PRIXPTR "\n", (int)(2 * sizeof(uintptr_t)), (uintptr_t)&y);
}