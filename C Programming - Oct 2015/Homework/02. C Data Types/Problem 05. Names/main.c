#include <stdio.h>
#include <stdlib.h>

/*
 * Declare two string (char array) variables holding your first name and 
 * last name. Print them in the console (mind adding an interval between them).
 * 
 * Tip: Make sure you properly declare the strings by 
 * specifying a correct size. Avoid buffer overflows.
 */
int main() 
{
    char firstName[5] = {'M', 'a', 'r', 'k', '\0'};
    char lastName[6] = {'T', 'w', 'a', 'i', 'n', '\0'};
    
    printf("%s %s\n", firstName, lastName);
    
    return (EXIT_SUCCESS);
}

