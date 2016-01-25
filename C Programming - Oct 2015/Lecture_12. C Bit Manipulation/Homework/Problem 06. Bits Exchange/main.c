#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(const char *, const _Bool);

int get_bit(const uint32_t, const uint32_t);
int get_bit_from_any_number(const size_t, const void * const, const uint32_t, 
        const _Bool, const _Bool);

int write_bit(uint32_t *, const uint32_t, const uint32_t);
int write_bit_to_any_number(const size_t, const void * const, const uint32_t, 
        const uint8_t, const _Bool, const _Bool);

int swap_bit_x_with_bit_y(uint32_t *, const uint32_t, const uint32_t);
int swap_bit_x_with_bit_y_of_any_number(const size_t, 
        const void * const, const uint32_t, const uint32_t, 
        const _Bool, const _Bool);

char * decimal_to_any_base(const uint64_t, const uint8_t);
char * get_bits_representation_of_any_number(const size_t, const void * const, 
        const _Bool, const _Bool);

/*
 * Problem 6. Bits Exchange
 * 
 * Write a program that exchanges bits 3, 4 and 5 with bits 24, 25 and 26 of 
 * given 32-bit unsigned integer. Examples:
 *
 * ----------------------------------------------------------------------------------------------------
 *      n     |      binary representation of n     |            binary result            |   result   |
 * ----------------------------------------------------------------------------------------------------|
 * 1140867093 | 01000100 00000000 01000000 00010101 | 01000010 00000000 01000000 00100101 | 1107312677 |
 * ----------------------------------------------------------------------------------------------------|
 *  255406592 | 00001111 00111001 00110010 00000000 | 00001000 00111001 00110010 00111000 |  137966136 |
 * ----------------------------------------------------------------------------------------------------|
 * 4294901775 | 11111111 11111111 00000000 00001111 | 11111001 11111111 00000000 00111111 | 4194238527 |
 * ----------------------------------------------------------------------------------------------------|
 *       5351 | 00000000 00000000 00010100 11100111 | 00000100 00000000 00010100 11000111 |   67114183 |
 * ----------------------------------------------------------------------------------------------------|
 * 2369124121 | 10001101 00110101 11110111 00011001 | 10001011 00110101 11110111 00101001 | 2335569705 |
 * ----------------------------------------------------------------------------------------------------|  
 */
int main() 
{
    uint32_t num;
    
    printf("n = ");
    scanf("%u", &num);
    
    uint32_t copy_of_num = num;
    
    char * bits_of_num_before_modification = 
        get_bits_representation_of_any_number(sizeof(num), &num, true, true);
    if(NULL == bits_of_num_before_modification)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    if(-1 == swap_bit_x_with_bit_y_of_any_number(sizeof(num), &num, 3, 24, true, true))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    if(-1 == swap_bit_x_with_bit_y_of_any_number(sizeof(num), &num, 4, 25, true, true))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    if(-1 == swap_bit_x_with_bit_y_of_any_number(sizeof(num), &num, 5, 26, true, true))
    {
        error("Error", false);
        return (EXIT_FAILURE);
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
    
    printf(" -----------------------------------------------------------------------------------------------------\n");
    printf("|      n     |      binary representation of n     |            binary result            |   result   |\n");
    printf("|-----------------------------------------------------------------------------------------------------|\n");
    printf("| %10u | %35s | %35s | %10u |\n", copy_of_num, 
        bits_of_num_before_modification, bits_of_num, num);
    printf("|-----------------------------------------------------------------------------------------------------|\n");

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

int get_bit(const uint32_t num, const uint32_t pos)
{
    if((8 * sizeof(uint32_t)) <= pos)
        return -1;
    
    if(((num >> pos) & 1) == 1)
        return 1;
    else
        return 0;
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

int write_bit(uint32_t * num, const uint32_t pos, const uint32_t bit)
{
    if((8 * sizeof(uint32_t)) <= pos)
        return -1;
    
    if(bit != 0 && bit != 1)
        return -1;
    
    uint32_t clearing_bit_mask = ~((uint32_t)1 << pos);
    
    *num = (*num & clearing_bit_mask) | (bit << pos);
    
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

int swap_bit_x_with_bit_y(uint32_t * num, 
        const uint32_t pos_x, const uint32_t pos_y)
{
    if((8 * sizeof(uint32_t)) <= pos_x)
        return -1;
    
    if((8 * sizeof(uint32_t)) <= pos_y)
        return -1;
    
    if(pos_x == pos_y)
        return 0;
    
    uint8_t bit_x = get_bit_from_any_number(sizeof(uint32_t), num, pos_x, true, true);
    if(-1 == bit_x) return -1;
    
    uint8_t bit_y = get_bit_from_any_number(sizeof(uint32_t), num, pos_y, true, true);
    if(-1 == bit_y) return -1;
    
    if(-1 == write_bit_to_any_number(sizeof(uint32_t), num, pos_x, bit_y, true, true))
        return -1;
    
    if(-1 == write_bit_to_any_number(sizeof(uint32_t), num, pos_y, bit_x, true, true))
        return -1;
    
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

char * decimal_to_any_base(const uint64_t decimal, const uint8_t base)
{
    // max to base 36
    
    char digits[36] = {
        '0','1','2','3','4','5','6','7',
        '8','9','A','B','C','D','E','F',
        'G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V',
        'W','X','Y','Z'};
    
    char * result = (char *)malloc(BUFFER_LENGTH);
    if(NULL == result)
    {
        error("Error", false);
        return NULL;
    }
    
    uint64_t quotient = decimal;
    int remainder;  
    
    int i = 0;
    uint32_t total_len = BUFFER_LENGTH;
    do
    {
        remainder = (int)(quotient % base);
        quotient = quotient / base;      
        
        if(i == (total_len - 1))
        {
            char * new_result = 
                (char *)realloc(result, total_len + BUFFER_LENGTH);
            
            if(NULL == new_result)
            {
                error("Error", false);
                return NULL;
            }
            else
            {
                result = new_result;
            }
        }
        
        result[i++] = digits[remainder];
    }while(quotient > 0);
    
    result[i] = '\0';
    
    /* Reverse string */

    int j;
    for(j = 0; j < i/2; j++)
    {
        // reverse chars of result by swap
        
        result[j] ^= result[i - j - 1];
        result[i - j - 1] ^= result[j];
        result[j] ^= result[i - j - 1];
    }
    
    return result;
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