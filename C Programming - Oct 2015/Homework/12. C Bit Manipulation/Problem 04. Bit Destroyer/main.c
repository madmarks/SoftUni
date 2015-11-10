#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 100

void error(const char *, const _Bool);
int write_bit(uint32_t *, const uint32_t, const uint32_t);

/*
 * Problem 4. Bit Destroyer
 * 
 * Write a program that sets the bit at position p to 0. 
 * Print the resulting number.
 * 
 * ---------------------
 *    n  |  p  | Result |
 * ---------------------|
 *  1313 |  5  |  1281  |
 * ---------------------|
 *   231 |  2  |   227  |
 * ---------------------|
 *   111 |  6  |   47   |
 * ---------------------|
 */
int main() 
{
    uint32_t n;
    uint32_t p;
    
    printf("n = ");
    scanf("%u", &n);
    
    printf("p = ");
    scanf("%u", &p);
    
    if(-1 == write_bit(&n, p, 0))
    {
        error("Error", false);
        return (EXIT_FAILURE);
    }

    printf("\nResult\n");
    printf("%u\n", n);

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