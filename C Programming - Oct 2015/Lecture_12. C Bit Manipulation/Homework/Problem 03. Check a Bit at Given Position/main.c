#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int get_bit(const uint32_t, const uint32_t);

/*
 * Problem 3. Check a Bit at Given Position
 * 
 * Write a Boolean expression that returns if the bit at position p (counting 
 * from 0, starting from the right) in given integer number n has value of 1. 
 * Examples:
 * 
 * -----------------------------------------------------
 *     n   | binary representation |  p  | bit @ p == 1 |
 * -----------------------------------------------------|
 *       5 |   00000000 00000101   |  2  |     true     |
 * -----------------------------------------------------|
 *       0 |   00000000 00000000   |  9  |     false    |
 * -----------------------------------------------------|
 *      15 |   00000000 00001111   |  1  |     true     |
 * -----------------------------------------------------|
 *    5343 |   00010100 11011111   |  7  |     true     |
 * -----------------------------------------------------|
 *   62241 |   11110011 00100001   | 11  |     false    |
 * -----------------------------------------------------|
 */
int main() 
{
    uint32_t n;
    uint32_t p;
    
    printf("n = ");
    scanf("%u", &n);
    
    printf("p = ");
    scanf("%u", &p);

    printf("\nbit @ p == 1\n");
    printf("%s\n", (get_bit(n, p) == 1) ? "true" : "false");

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