#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

void error(const char *, const _Bool);

int get_bit_from_any_number(const size_t, const void * const, const uint32_t, 
        const _Bool, const _Bool);

int get_count_of_one_bits_of_any_number(const size_t, const void * const, 
        const uint32_t, const uint32_t, const _Bool, const _Bool);

int write_bit_to_any_number(const size_t, const void * const, const uint32_t, 
        const uint8_t, const _Bool, const _Bool);

/*
 * Problem 9. ** Bit Sifting
 * 
 * This problem is from Variant 3 of C# Basics exam from 11-04-2014 Morning. You
 * can test your solution at http://judge.softuni.bg/Contests/Practice/Index/4#4
 * 
 * In this problem we'll be sifting bits through sieves (sift = пресявам, 
 * sieve = сито).
 * 
 * You will be given an integer, representing the bits to sieve, and several 
 * more numbers, representing the sieves the bits will fall through. Your task 
 * is to follow the bits as they fall down, and determine what comes out of the 
 * other end.
 * 
 * 
 * Example
 * 
 * For this example, imagine we are working with 8-bit integers (the actual 
 * problem uses 64-bit ones). Let the initial bits be given as 165 (10100101 in 
 * binary), and the sieves be 138 (10001010), 84 (01010100) and 154 (10011010). 
 * The 1 bits from the initial number fall through the 0 bits of the sieves and 
 * stop if they reach a 1 bit; if they make it to the end, they become a part of 
 * the final number.
 * 
 * In this case, the final number is 33 (00100001), which has two 1 bits in its 
 * binary form - the answer is 2.
 * 
 * 10100101
 * | |  | |
 * 10001010
 *   |  | |
 * 01010100
 *   |    |
 * 10011010
 *   |    |
 * 00100001
 * 
 * 
 * Input
 * 
 * The input data should be read from the console.
 * 
 *   * On the first line of input, you will read an integer representing the 
 *     bits to sieve.
 *   * On the second line of input, you will read an integer N representing the 
 *     number of sieves.
 *   * On the next N lines of input, you will read N integers representing the 
 *     sieves.
 * 
 * The input data will always be valid and in the format described. There is no 
 * need to check it.
 * 
 * 
 * Output
 * 
 * The output must be printed on the console.
 * 
 * On the single line of the output you must print the count of "1" bits in the 
 * final result.
 * 
 * Constraints
 * 
 *   * All numbers in the input will be between 0 and 18,446,744,073,709,551,615.
 *   * The count of sieves N is in range [0 ... 100].
 *   * Allowed work time for your program: 0.25 seconds.
 *   * Allowed memory: 16 MB.
 * 
 * Examples
 * 
 *  ------------------------------
 * |        Input        | Output |
 * |------------------------------|
 * | 584938644408189469  | 4      |
 * | 3                   |        |
 * | 1817781288526917737 |        |
 * | 8601652436058397548 |        |
 * | 51827709899390606   |        |
 *  ------------------------------
 * 
 *  ------------------------------
 * |        Input        | Output |
 * |------------------------------|
 * | 918045605434484408  | 35     |
 * | 0                   |        |
 * |                     |        |
 *  ------------------------------
 * 
 *  ------------------------------
 * |        Input        | Output |
 * |------------------------------|
 * | 5019588773529942006 | 17     |
 * | 1                   |        |
 * | 5295337384025297044 |        |
 * |                     |        |
 *  ------------------------------
 */
int main() 
{
    unsigned long long num;
    uint32_t count_of_sieves;
    
    printf("num = ");
    scanf("%llu", &num);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
    
    printf("N = ");
    scanf("%u", &count_of_sieves);
    
    // flush stdin
    while ((c = getchar()) != '\n' && c != EOF);
    
    unsigned long long * arr = 
        (unsigned long long *)malloc(count_of_sieves * sizeof(unsigned long long));
    if(NULL == arr)
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }
    
    size_t i;
    for(i = 0; i < count_of_sieves; i++)
    {
        scanf("%llu", &(arr[i]));
        
        // flush stdin
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    size_t j;
    int bit_of_num;
    int bit_of_arr_num;
    for(i = 0; i < count_of_sieves; i++)
    {
        for(j = 0; j < 64; j++)
        {
            bit_of_num = get_bit_from_any_number(sizeof(unsigned long long), 
                    &num, j, true, true);
            
            bit_of_arr_num = get_bit_from_any_number(sizeof(unsigned long long), 
                    &(arr[i]), j, true, true);
            
            if(bit_of_num == 1 && bit_of_arr_num == 1)
            {
                write_bit_to_any_number(sizeof(unsigned long long), &num, j, 0, 
                        true, true);
            }
        }        
    }
    
    int count_of_one_bits = 
        get_count_of_one_bits_of_any_number(sizeof(unsigned long long), &num, 
            0, 63, true, true);
    
    printf("\nOutput\n");
    printf("%d\n", count_of_one_bits);
    
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

int get_count_of_one_bits_of_any_number(const size_t size_of_type, 
        const void * const ptrNum, const uint32_t start_pos,
        const uint32_t end_pos, const _Bool littleEndian, 
        const _Bool bits_counted_from_the_rightmost)
{
    if((8 * size_of_type) <= start_pos || (8 * size_of_type) <= end_pos)
        return -1;
    
    if(start_pos > end_pos)
        return -1;
    
    size_t i;
    int bit;
    int count = 0;
    for(i = start_pos; i <= end_pos; i++)
    {
        if(-1 != (bit = get_bit_from_any_number(size_of_type, ptrNum, i, littleEndian, 
                bits_counted_from_the_rightmost)))
        {
            count += bit;
        }
        else
        {
            error("Error", false);
            return -1;
        }
    }
    
    return count;
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