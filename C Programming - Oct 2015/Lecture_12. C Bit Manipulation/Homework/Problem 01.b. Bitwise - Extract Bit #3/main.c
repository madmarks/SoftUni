#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int get_bit(const uint32_t, const uint32_t);

/*
 * Problem 01.b. Bitwise: Extract Bit #3
 * 
 * Using bitwise operators, write an expression for finding the value of the 
 * bit #3 of a given unsigned integer. The bits are counted from right to left, 
 * starting from bit #0. The result of the expression should be either 1 or 0.
 * Examples:
 * 
 * -----------------------------------------
 *     n   | binary representation | Result |
 * -----------------------------------------|
 *       5 |   00000000 00000101   |   0    |
 * -----------------------------------------|
 *       0 |   00000000 00000000   |   0    |
 * -----------------------------------------|
 *      15 |   00000000 00001111   |   1    |
 * -----------------------------------------|
 *    5343 |   00010100 11011111   |   1    |
 * -----------------------------------------|
 *   62241 |   11110011 00100001   |   0    |
 * -----------------------------------------|
 */
int main() 
{
    uint32_t n;
    
    printf("n = ");
    scanf("%u", &n);

    printf("\nResult\n");
    printf("%d\n", get_bit(n, 3));

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