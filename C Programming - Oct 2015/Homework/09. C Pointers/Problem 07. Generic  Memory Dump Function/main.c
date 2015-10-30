#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

void error(char *);
void mem_dump(void *, int, int);

/*
 * Problem 07. Generic  Memory Dump Function
 * 
 * Write a function that takes a pointer of any type, size of bytes n and 
 * row length len. The function should print a total of n bytes, starting from 
 * the address of the pointer. 
 * 
 * The output should be formatted into several rows, each holding len bytes.
 * At the start of each row, print the address of the initial byte.
 * 
 * Note: The addresses may vary.
 * 
 * Input
 * char *text = "I love to break free";
 * mem_dump(text, strlen(text) + 1, 5);
 * 
 * Output
 * 0x400794     49 20 6c 6f 76 
 * 0x400799     65 20 74 6f 20 
 * 0x40079E     62 72 65 61 6b 
 * 0x4007A3     20 66 72 65 65 
 * 0x4007A8     00 
 * 
 * ---------------------------------------
 * 
 * Input
 * int array[] =  { 7, 3, 2, 10, -5 };
 * size_t size = sizeof(array) / sizeof(int);
 * mem_dump(array, size * sizeof(int), 4);
 * 
 * Output
 * 0x7FFDE0DFE2E0     07 00 00 00 
 * 0x7FFDE0DFE2E4     03 00 00 00 
 * 0x7FFDE0DFE2E8     02 00 00 00 
 * 0x7FFDE0DFE2EC     0a 00 00 00 
 * 0x7FFDE0DFE2F0     fb ff ff ff 
 */
int main() 
{
    char *text = "I love to break free";
    mem_dump(text, strlen(text) + 1, 5);
    
    int array[] =  { 7, 3, 2, 10, -5 };
    size_t size = sizeof(array) / sizeof(int);
    mem_dump(array, size * sizeof(int), 4);

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void mem_dump(void *ptr, int num_bytes, int row_len)
{
    int i = 0;
    
    while(i < num_bytes)
    {
        if(i % row_len == 0)
        {
            printf("\n0x%"PRIXPTR"     ", (uintptr_t)(ptr + i));
        }
        
        printf("%02x ", *(unsigned char *)(ptr + i));
        
        i++;
    }
    
    printf("\n");
}