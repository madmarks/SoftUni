#include <stdio.h>
#include <stdlib.h>

int new_integer();
int* new_integer_ptr();

/*
 * Problem 05. Create New Integer
 * 
 * Write a function that declares and initializes an integer on the stack, then
 * returning it. Try creating the function with two different declarations:
 * 
 * int new_integer()
 * int* new_integer_ptr()
 * 
 * What is the difference between the two declarations? Why is the second 
 * declaration not safe to use? Give an example.
 */
int main() 
{
    int a;
    int b;
    
    a = new_integer();
    printf("a = %d\n", a);
    
    b = *new_integer_ptr();
    printf("\nb = %d\nb = *new_integer_ptr(); is undefined behavior!", b);
    printf(" Switch between Debug and Release and run this program.\n");
    
    printf("\nThe local variables have a lifetime which extends only inside ");
    printf("the block in which it is defined. \nThe moment the control goes");
    printf(" outside the block in which the local variable is defined, the ");
    printf("storage for \nthe variable is no more allocated (not guaranteed). ");
    printf("Using the memory address of the variable outside \nthe lifetime ");
    printf("area of the variable will be undefined behaviour.\n");

    return (EXIT_SUCCESS);
}

int new_integer()
{
    int a = 3;
    
    return a;
}

int* new_integer_ptr()
{
    int b = 3;
    
    return &b;
}