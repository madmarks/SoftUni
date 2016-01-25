#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(const char *, const _Bool);

int get_bit_from_any_number(const size_t, const void * const, const uint32_t, 
        const _Bool, const _Bool);

int write_bit_to_any_number(const size_t, const void * const, const uint32_t, 
        const uint8_t, const _Bool, const _Bool);

int swap_bit_x_with_bit_y_of_any_number(const size_t, 
        const void * const, const uint32_t, const uint32_t, 
        const _Bool, const _Bool);

char * get_bits_representation_of_any_number(const size_t, const void * const, 
        const _Bool, const _Bool);

/*
 * Problem 7. Bits Exchange (Advanced)
 * 
 * Write a program that exchanges bits {p, p+1, ..., p+k-1} with bits
 * {q, q+1, ..., q+k-1} of a given 32-bit unsigned integer. The first and the 
 * second sequence of bits may not overlap. Examples:
 * 
 * -------------------------------------------------------------------------------------------------------------------------
 *       n     |  p  |  q  |  k  |      binary representation of n     |            binary result            |    result    |
 * -------------------------------------------------------------------------------------------------------------------------|
 *  1140867093 |   3 |  24 |   3 | 01000100 00000000 01000000 00010101 | 01000010 00000000 01000000 00100101 |   1107312677 |
 * -------------------------------------------------------------------------------------------------------------------------|
 *  4294901775 |  24 |   3 |   3 | 11111111 11111111 00000000 00001111 | 11111001 11111111 00000000 00111111 |   4194238527 |
 * -------------------------------------------------------------------------------------------------------------------------|
 *  2369124121 |   2 |  22 |  10 | 10001101 00110101 11110111 00011001 | 01110001 10110101 11111000 11010001 |   1907751121 |
 * -------------------------------------------------------------------------------------------------------------------------|
 *   987654321 |   2 |   8 |  11 |                  -                  |                  -                  |  overlapping |
 * -------------------------------------------------------------------------------------------------------------------------|
 *   123456789 |  26 |   0 |   7 |                  -                  |                  -                  | out of range |
 * -------------------------------------------------------------------------------------------------------------------------|
 * 33333333333 |  -1 |   0 |  33 |                  -                  |                  -                  | out of range |
 * -------------------------------------------------------------------------------------------------------------------------|
 */
int main() 
{
    uint32_t num;
    uint32_t p;
    uint32_t q;
    int k;
    
    printf("n = ");
    scanf("%u", &num);
    
    printf("p = ");
    scanf("%u", &p);
    
    printf("q = ");
    scanf("%u", &q);
    
    printf("k = ");
    scanf("%d", &k);
    
    if(p < 0 || (p + k) > (8 * sizeof(p)))
    {
        printf("\nout of range\n");
        return (EXIT_FAILURE);
    }
    
    if(q < 0 || (q + k) > (8 * sizeof(q)))
    {
        printf("\nout of range\n");
        return (EXIT_FAILURE);
    }
    
    if((q <= p && ((p - q) < k)) || (q > p && ((q - p) < k)))
    {
        printf("\noverlapping\n");
        return (EXIT_FAILURE);
    }
    
    uint32_t copy_of_num = num;
    
    char * bits_of_num_before_modification = 
        get_bits_representation_of_any_number(sizeof(num), 
            (const void * const)&num, true, true);
    if(NULL == bits_of_num_before_modification)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i;
    for(i = 0; i < k; i++)
    {
        if(-1 == swap_bit_x_with_bit_y_of_any_number(sizeof(num), &num, 
                p + i, q + i, true, true))
        {
            error("Error", false);
            return (EXIT_FAILURE);
        }        
    }
    
    printf("\nResult\n");
    printf("%u\n", num);
     
    char * bits_of_num = get_bits_representation_of_any_number(sizeof(num), 
            &num, true, true);
    if(NULL == bits_of_num)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    printf(" ------------------------------------------------------------------------------------------------------------------------\n");
    printf("|      n      |  p  |  q  |  k  |      binary representation of n     |            binary result            |   result   |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %11u | %3u | %3u | %3d | %35s | %35s | %10u |\n", copy_of_num, 
        p, q, k, bits_of_num_before_modification, bits_of_num, num);
    printf("|------------------------------------------------------------------------------------------------------------------------|\n");

    /* Free allocated memory */
    
    free(bits_of_num_before_modification);
    free(bits_of_num);    

    return (EXIT_SUCCESS);
}

void error(const char *msg, const _Bool output_to_log_file)
{
    if (errno)
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    else
        fprintf(stderr, "%s\n", strerror(errno));
    
    if(output_to_log_file)
    {
        FILE * logfile = fopen("log.txt", "a");
        if(logfile)
        {
            printf("\n---------------------------------------\n");
            if (errno)
                fprintf(logfile, "%s: %s\n", msg, strerror(errno));
            else
                fprintf(logfile, "%s\n", strerror(errno));

            free(logfile);
        }
    }
}

int get_bit_from_any_number(const size_t size_of_type, const void * const ptrNum, 
        const uint32_t pos, const _Bool littleEndian, 
        const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= pos)
        return -1;
    
    unsigned char *pByte = (unsigned char *)ptrNum;
    int index;
    int shift_count;
    
    if(littleEndian)
        index = pos / 8;
    else
        index = size_of_type - (pos / 8) - 1;
    
    if(bits_counted_from_the_rightmost)
        shift_count = pos % 8;
    else
        shift_count = 7 - (pos % 8);
    
    if((pByte[index] >> shift_count) & 1)
        return 1;
    else
        return 0;
}

int write_bit_to_any_number(const size_t size_of_type, const void * const ptrNum, 
        const uint32_t pos, const uint8_t bit, const _Bool littleEndian, 
        const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= pos)
        return -1;
    
    if(bit != 0 && bit != 1)
        return -1;
    
    unsigned char *pByte = (unsigned char *)ptrNum;
    int index;
    int shift_count;
    
    if(littleEndian)
        index = pos / 8;
    else
        index = size_of_type - (pos / 8) - 1; 
    
    if(bits_counted_from_the_rightmost)
        shift_count = pos % 8;
    else
        shift_count = 7 - (pos % 8);
    
    uint8_t clearing_bit_mask = ~((uint8_t)1 << shift_count);
    
    pByte[index] = (pByte[index] & clearing_bit_mask) | (bit << shift_count);
    
    return 0;
}

int swap_bit_x_with_bit_y_of_any_number(const size_t size_of_type, 
        const void * const ptrNum, const uint32_t pos_x, const uint32_t pos_y, 
        const _Bool littleEndian, const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= pos_x)
        return -1;
    
    if((8 * size_of_type) <= pos_y)
        return -1;
    
    if(pos_x == pos_y)
        return 0;
    
    uint8_t bit_x = get_bit_from_any_number(size_of_type, ptrNum, pos_x, 
            littleEndian, bits_counted_from_the_rightmost);
    if(-1 == bit_x) return -1;
    
    uint8_t bit_y = get_bit_from_any_number(size_of_type, ptrNum, pos_y, 
            littleEndian, bits_counted_from_the_rightmost);
    if(-1 == bit_y) return -1;
    
    if(-1 == write_bit_to_any_number(size_of_type, ptrNum, pos_x, bit_y, 
            littleEndian, bits_counted_from_the_rightmost))
        return -1;
    
    if(-1 == write_bit_to_any_number(size_of_type, ptrNum, pos_y, bit_x, 
            littleEndian, bits_counted_from_the_rightmost))
        return -1;
    
    return 0;
}

char * get_bits_representation_of_any_number(const size_t size_of_type, 
        const void * const ptrNum, const _Bool littleEndian, 
        const _Bool divide_bytes_with_space)
{
    int i, j;
    int idx = 0;
    int len = divide_bytes_with_space ? 
        ((size_of_type - 1) + size_of_type * 8 + 1) : (size_of_type * 8 + 1);
    
    unsigned char *pByte = (unsigned char *)ptrNum;
    
    unsigned char *bits = (unsigned char *)malloc(len); // +1 for '\0'
    if(NULL == bits)
    {
        error("Not enough memory!", false);
        return NULL;
    }
    
    if(littleEndian)
    {
        for (i = size_of_type - 1; i >= 0; i--)
        {
            for (j = 7; j >= 0; j--)
                bits[idx++] = 0x30 ^ (pByte[i] >> j) & 1; // 0x30 -> '0'
            
            if(divide_bytes_with_space && i != 0)
                bits[idx++] = 0x20;
        }
    }
    else
    {
        for (i = 0; i < size_of_type; i++)
        {
            for (j = 7; j >= 0; j--)
                bits[idx++] = 0x30 ^ (pByte[i] >> j) & 1;
            
            if(divide_bytes_with_space && i != (size_of_type - 1))
                bits[idx++] = 0x20;
        }
    }
    
    bits[idx] = 0;
    
    return bits; // must free(bits) where function is called
}