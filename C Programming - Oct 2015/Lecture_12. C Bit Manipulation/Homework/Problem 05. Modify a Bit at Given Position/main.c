#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(const char *, const _Bool);
int write_bit(uint32_t *, const uint32_t, const uint32_t);
char * decimal_to_any_base(const uint64_t, const uint8_t);
char * get_bits_representation_of_any_number(const size_t, const void * const, 
        const _Bool, const _Bool);

/*
 * Problem 5. Modify a Bit at Given Position
 * 
 * We are given an integer number n, a bit value v (v = 0 or 1) and a position p. 
 * Write a sequence of operators (a few lines of C code) that modifies n to hold 
 * the value v at the position p from the binary representation of n while 
 * preserving all other bits in n. Examples:
 * 
 * ----------------------------------------------------------------------------
 *    n  | binary representation of n |  p  |  v  |   binary result   | result |
 * ----------------------------------------------------------------------------|
 *     5 |      00000000 00000101     |  2  |  0  | 00000000 00000001 |      1 |
 * ----------------------------------------------------------------------------|
 *     0 |      00000000 00000000     |  9  |  1  | 00000010 00000000 |    512 |
 * ----------------------------------------------------------------------------|
 *    15 |      00000000 00001111     |  1  |  1  | 00000000 00001111 |     15 |
 * ----------------------------------------------------------------------------|
 *  5343 |      00010100 11011111     |  7  |  0  | 00010100 01011111 |   5215 |
 * ----------------------------------------------------------------------------|
 * 62241 |      11110011 00100001     | 11  |  0  | 11110011 00100001 |  62241 |
 * ----------------------------------------------------------------------------|
 */
int main() 
{
    uint32_t num;
    uint32_t p;
    uint32_t v;
    
    printf("n = ");
    scanf("%u", &num);
    
    uint32_t copy_of_num = num;
    
//    char * bits_of_num_before_modification = 
//        decimal_to_any_base((uint64_t)num, 2);
    char * bits_of_num_before_modification = 
        get_bits_representation_of_any_number(sizeof(num), &num, true, true);
    
    printf("p = ");
    scanf("%u", &p);
    
    printf("v = ");
    scanf("%u", &v);
    
    if(-1 == write_bit(&num, p, v))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }

    printf("\nResult\n");
    printf("%u\n", num);

//    char * bits_of_num = decimal_to_any_base((uint64_t)num, 2);     
    char * bits_of_num = 
        get_bits_representation_of_any_number(sizeof(num), &num, true, true);
    
    printf(" --------------------------------------------------------------------------------------------------------\n");
    printf("|   n   |      binary representation of n     |  p  |  v  |            binary result            | result |\n");
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    printf("| %5u | %35s | %3d | %2d  | %35s | %6u |\n", copy_of_num, 
        bits_of_num_before_modification, p, v, bits_of_num, num);
    printf("|--------------------------------------------------------------------------------------------------------|\n");
    
    /* Free allocated memory */
    
    if(bits_of_num_before_modification)
        free(bits_of_num_before_modification);
    
    if(bits_of_num)
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