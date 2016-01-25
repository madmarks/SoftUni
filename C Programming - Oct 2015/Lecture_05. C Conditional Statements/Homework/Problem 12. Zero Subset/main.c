#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Problem 12. Zero Subset
 * 
 * We are given 5 integer numbers. Write a program that finds all subsets of 
 * these numbers whose sum is 0. Assume that repeating the same subset several 
 * times is not a problem. 
 */
int main() 
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int bits[5];
    int lastEquationMember;
    _Bool hasZeroSubset = false;
    int sum;
    
    printf("Input 5 integer numbers: ");
    int matches = scanf("%i %i %i %i %i", &a, &b, &c, &d, &e);
   
    if(matches != 5)
    {
        printf("Wrong input!\n");
        return (EXIT_FAILURE);
    }
    
    int i;
    for(i = 3; i < 32; i++)
    {
        if(i == 4 || i == 8 || i == 16) 
            continue;
        
        bits[4] = (i >> 4) & 0x01;
        bits[3] = (i >> 3) & 0x01;
        bits[2] = (i >> 2) & 0x01;
        bits[1] = (i >> 1) & 0x01;
        bits[0] = i & 0x01;
        
        sum = 0;
        
        if(bits[4]) 
            sum += a;
        if(bits[3]) 
        {
            sum += b;
            lastEquationMember = 3;
        }
        if(bits[2]) 
        {
            sum += c;
            lastEquationMember = 2;
        }
        if(bits[1]) 
        {
            sum += d;
            lastEquationMember = 1;
        }
        if(bits[0]) 
        {
            sum += e;
            lastEquationMember = 0;
        }

        if(sum == 0)
        {
            hasZeroSubset = true;
            
            if(bits[4]) 
                printf("%i + ", a);
            
            if(bits[3])
                if(lastEquationMember == 3) 
                    printf("%i", b);
                else
                    printf("%i + ", b);
            
            if(bits[2])
                if(lastEquationMember == 2) 
                    printf("%i", c);
                else
                    printf("%i + ", c);
            
            if(bits[1])
                if(lastEquationMember == 1) 
                    printf("%i", d);
                else
                    printf("%i + ", d);
            
            if(bits[0]) 
                printf("%i", e);
                
            printf(" = 0\n");
        }
    }
    
    if(!hasZeroSubset)
    {
        printf("no zero subset\n");
    }

    return (EXIT_SUCCESS);
}

