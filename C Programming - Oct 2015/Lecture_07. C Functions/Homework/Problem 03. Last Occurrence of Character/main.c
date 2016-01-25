#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH_MAX 100

int lastIndexOf(char *str, int length, char ch);

/*
 * Problem 3. Last Occurrence of Character
 * 
 * Write a function that takes determines the position of the rightmost 
 * occurrence of a character ch in a string str. If no such character exists, 
 * the function should return -1.
 */
int main() 
{
    char ch;
    char str[STRING_LENGTH_MAX];
    
    printf("Input string: ");
    fgets(str, STRING_LENGTH_MAX, stdin);
    
    int length = strlen(str);
    if(str[length - 1] == '\n')
        str[length - 1] = '\0';
    
    printf("Input char: ");
    scanf("%c", &ch);
    
    int lastIndex = lastIndexOf(str, length, ch);
    
    if(lastIndex != -1)
    {
        printf("\nPosition of the rightmost occurrence of \'%c\' is: %i\n",
            ch, lastIndex);
    }
    else
    {
        printf("\n-1 : character \'%c\' does not exist in the given string\n", ch);
    }
    
    // Test data:
    //
    // Sir Stanley Royce
    // AAAAAAA
    // Do NOT run this command:  :(){ :|: & };:

    return (EXIT_SUCCESS);
}

int lastIndexOf(char *str, int length, char ch)
{
    //int length = strlen(str);
    
    int i = length - 1;
    while(i >= 0)
    {
        if(str[i] == ch)
        {
            return i;
        }
        
        i--;
    }
    
    return -1;
}