#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

void error(const char *, const _Bool);

int write_bit_to_any_number(const size_t, const void * const, const uint32_t, 
        const uint8_t, const _Bool, const _Bool);

/*
 * Problem 8. ** Bits Up
 * 
 * This problem is from Variant 2 of C# Basics exam from 10-04-2014 Evening. You
 * can test your solution: http://judge.softuni.bg/Contests/Practice/Index/3#4
 * 
 * You are given a sequence of bytes. Consider each byte as sequences of exactly
 * 8 bits. You are given also a number step. Write a program to set to 1 the 
 * bits at positions: 1, 1 + step, 1 + 2*step, ... . Print the output as a 
 * sequence of bytes.
 * 
 * Bits in each byte are counted from the leftmost to the rightmost. Bits are 
 * numbered starting from 0.
 * 
 * 
 * Input
 * 
 *   * The input data should be read from the console.
 *   * The number n stays at the first line.
 *   * The number step stays at the second line.
 *   * At each of the next n lines n bytes are given, each at a separate line. 
 * 
 * The input data will always be valid and in the format described. There is no 
 * need to check it explicitly.
 * 
 * 
 * Output
 * 
 * The output should be printed on the console. Print exactly n bytes, each at a 
 * separate line and in range [0..255], obtained by applying the bit inversions 
 * over the input sequence.
 * 
 * 
 * Constraints
 * 
 *   * The number n will be an integer number in the range [1 ... 100].
 *   * The number step will be an integer number in the range [1 ... 20].
 *   * The n numbers will be integers in the range [0 ... 255].
 *   * Allowed working time for your program: 0.25 seconds.
 *   * Allowed memory: 16MB.
 * 
 * Examples
 * 
 *  ---------------------------------------------------------------------------|
 * | Input | Output |                        Coments                           |
 * |---------------------------------------------------------------------------|
 * | 2     | 109    | We have the following sequence of 16 bits (2 bytes):     |
 * | 11    | 95     | 01101101 01010111                                        |
 * | 109   |        | We invert the bits 1 and 12 (step = 11). We get:           |
 * | 87    |        | 01101101 01011111                                        |
 * |---------------------------------------------------------------------------|
 * | 3     | 111    | We have the following sequence of 24 bits (3 bytes):     |
 * | 5     | 87     | 00101101 01010111 11111010                               |
 * | 45    | 254    | We invert the bits 1, 6, 11, 16 and 21 (step=5). We get: |
 * | 87    |        | 01101111 01010111 11111110                               |
 * | 250   |        |                                                          |
 * |---------------------------------------------------------------------------|
 */
int main() 
{
    uint32_t n;
    uint32_t step;
    
    printf("n = ");
    scanf("%u", &n);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("step = ");
    scanf("%u", &step);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    while ((c = getchar()) != '\n' && c != EOF);
    
    uint8_t * arr = (uint8_t *)malloc(n);
    if(NULL == arr)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i;
    uint32_t tmp;
    for(i = 0; i < n; i++)
    {
        scanf("%u", &tmp);
        arr[i] = (uint8_t)tmp;
        
        // flush stdin because of unread newline or other unexpected 
        // input after calling scanf 
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    uint32_t bit_number_to_set = 1;
    while(bit_number_to_set < (8 * n))
    {
        write_bit_to_any_number(n, arr, bit_number_to_set, 1, true, false);
        
        bit_number_to_set += step;
    }
    
    printf("\nOutput\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    /* Free allocated memory */
    
    free(arr);

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