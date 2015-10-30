#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 6. Print First and Last Name
 * 
 * Create console application that prints your first and last name, 
 * each at a separate line.
 */
int main() 
{
    char firstName[] = "Bob";
    char lastName[] = "Dylan";
    
    printf("%s\n%s\n", firstName, lastName);
    
    return (EXIT_SUCCESS);
}