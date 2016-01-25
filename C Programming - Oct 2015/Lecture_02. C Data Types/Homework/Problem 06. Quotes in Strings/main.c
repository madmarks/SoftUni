#include <stdio.h>
#include <stdlib.h>

/*
 * Declare a string variable and assign to it the following value:
 * 
 * The "use" of quotations causes difficulties. \n, \t and \ are also special characters.
 */
int main() 
{
    char *str = "The \"use\" of quotations causes difficulties. \\n, \\t and \\ are also special characters.";
    
    printf("%s\n", str);
    
    return (EXIT_SUCCESS);
}

