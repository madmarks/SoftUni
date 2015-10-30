#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int printNumbersInIntervalDividebleByGivenNumber(
    unsigned int const start, 
    unsigned int const end, 
    unsigned int const divider)
{
    unsigned int i;
    unsigned int count = 0;
    
    for(i = start; i <= end; i++)
    {
        if((i % divider) == 0)
        {
            printf("%u ", i);
            count++;
        }
    }
    
    return count;
}

/*
 * Problem 09. Numbers in Interval Dividable by Given Number
 * 
 * Write a program that reads two positive integer numbers and prints how many 
 * numbers p exist between them such that the reminder of the division by 5 is 0. 
 */
int main() 
{
    unsigned int start;
    unsigned int end;
    unsigned int divider = 5;
    unsigned int count = 0;
    
    do
    {
        printf("Input start = ");
        scanf("%u", &start);
        
        if(start < 1)
        {
            printf("Error: start must be >= 1\n\n");
        }
        else
        {
            printf("Input end = ");
            scanf("%u", &end);

            if(end < 1)
            {
                printf("Error: end must be >= 1\n\n");
            }
        }
    }while(start < 1 || end < 1);
    
    printf("| start |  end  |   p   |     result     \n");
    printf("| %5u | %5u | %5u | ", start, end, count);
    
    count = printNumbersInIntervalDividebleByGivenNumber(start, end, divider);
    
    printf("\r| %5u | %5u | %5u | ", start, end, count);
    printf("\n");

    return (EXIT_SUCCESS);
}

