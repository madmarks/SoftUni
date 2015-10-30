#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 8. Print a Sequence
 * 
 * Write a program that prints the first 10 members 
 * of the sequence: 2, -3, 4, -5, 6, -7, ..
 * 
 * Extra: Modify your program to read a number n from the console and 
 * then finds the first n members from the sequence, starting from 2. 
 */
int main() 
{
    int i;
    int length;
    
    printf("Enter length of sequence (2 <= length <= 100) : ");
    scanf("%u", &length);
    
    if(length < 2 || 100 < length)
    {
        printf("Error. Wrong length!");
        return (EXIT_FAILURE);
    }
    
    char *sequence = malloc(length);
    
    if(sequence != NULL)
    {
        for(i=0; i<length; i++)
        {
            sequence[i] = (i%2 == 0) ? i+2 : -(i+2);

            printf("%d", sequence[i]);
            if(i != (length - 1))
            {
                printf(", ");
            }
        }
        
        free(sequence);
    }
    
    return (EXIT_SUCCESS);
}