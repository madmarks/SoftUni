#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int get_bit(const uint32_t, const uint32_t);

/*
 * Problem 1.a. First Bit
 * 
 * Write a program that prints the bit at position 1 of a number.
 * 
 * ------------------
 *     n   |  Result |
 * ------------------|
 *     2   |    1    |
 * ------------------|
 *    51   |    1    |
 * ------------------|
 *    13   |    0    |
 * ------------------|
 *    24   |    0    |
 * ------------------
 */
int main() 
{
    uint32_t n;
    
    printf("n = ");
    scanf("%u", &n);

    printf("\nResult\n");
    printf("%d\n", get_bit(n, 1));

    return (EXIT_SUCCESS);
}

int get_bit(const uint32_t num, const uint32_t pos)
{
    if((8 * sizeof(uint32_t)) <= pos)
        return -1;
    
    if(((num >> pos) & 1) == 1)
        return 1;
    else
        return 0;
}