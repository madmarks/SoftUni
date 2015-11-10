#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int get_bit(const uint32_t, const uint32_t);

/*
 * Problem 02. Extract Bit from Integer
 * 
 * Write an expression that extracts from given integer n the value of given 
 * bit at index p. Examples:
 * 
 * ------------------------------------------------
 *     n   | binary representation |  p  | bit @ p |
 * ------------------------------------------------|
 *       5 |   00000000 00000101   |  2  |    1    |
 * ------------------------------------------------|
 *       0 |   00000000 00000000   |  9  |    0    |
 * ------------------------------------------------|
 *      15 |   00000000 00001111   |  1  |    1    |
 * ------------------------------------------------|
 *    5343 |   00010100 11011111   |  7  |    1    |
 * ------------------------------------------------|
 *   62241 |   11110011 00100001   | 11  |    0    |
 * ------------------------------------------------|
 */
int main() 
{
    uint32_t n;
    uint32_t p;
    
    printf("n = ");
    scanf("%u", &n);
    
    printf("p = ");
    scanf("%u", &p);

    printf("\nbit @ p\n");
    printf("%d\n", get_bit(n, p));

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