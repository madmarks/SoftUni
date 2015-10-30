#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char *getBits(size_t const size, void const * const ptr, 
        _Bool const littleEndian)
{
    int i, j;
    int idx = 0;
    unsigned char *pByte = (unsigned char *)ptr;
    unsigned char *bits = (unsigned char *)malloc(size * 8 + 1); // +1 for '\0'
    
    if(littleEndian)
    {
        for (i = size-1; i >= 0; i--)
            for (j = 7; j >= 0; j--)
                bits[idx++] = 0x30 ^ (pByte[i] >> j) & 1;
    }
    else
    {
        for (i = 0; i < size; i++)
            for (j = 7; j >= 0; j--)
                bits[idx++] = 0x30 ^ (pByte[i] >> j) & 1;
    }
    bits[idx] = 0;
    
    return bits; // must free(bits) where function is called
}

/*
 * Problem 04. Formatting Numbers
 * 
 * Write a program that reads 3 numbers: an integer number a (0<=a<=500), 
 * a floating-point number b and a floating-point number c and prints them in 
 * 4 virtual columns on the console. Each column should have a width of 10 
 * characters. The number a should be printed in hexadecimal, left aligned; 
 * then the number a should be printed in binary form, padded  with zeroes, 
 * then the number b should be printed with 2 digits after the decimal point, 
 * right aligned; the number c should be printed with 3 digits after the decimal 
 * point, left aligned.
 */
int main() 
{
    unsigned short a;
    float b;
    float c;
    
    printf("\nInput integer number (0<=a<=500) a = ");
    scanf("%hu", &a);
    printf("Input floating-point number b = ");
    scanf("%f", &b);
    printf("Input floating-point number c = ");
    scanf("%f", &c);
    
    unsigned char *bits = getBits(sizeof(a), (const void *)&a, true);
    
    if(bits == NULL)
    {
        printf("Error when getting bits of number!\n");
        return (EXIT_FAILURE);
    }
        
    printf("\n|%-10X|%10s|%10.2f|%-10.3f|", 
            a, (unsigned char *)(bits + 6), b, c);

    free(bits);
    return (EXIT_SUCCESS);
}

