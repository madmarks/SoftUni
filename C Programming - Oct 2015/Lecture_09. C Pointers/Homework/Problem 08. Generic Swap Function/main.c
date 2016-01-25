#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error(char *);
void swap(void *, void *, size_t);

/*
 * Problem 08. Generic Swap Function
 * 
 * Write a function that takes 2 pointers and swaps the memory they point to. 
 * The function should also take the size of each memory piece and should 
 * work with any data type.
 * 
 * Sample Code
 * char letter = 'B', symbol = '+';
 * swap(&letter, &symbol, sizeof(char));
 * printf("%c %c", letter, symbol);
 * 
 * Output
 * + B
 * -----------------------------------------
 * Sample Code
 * int a = 10, b = 6; 
 * swap(&a, &b, sizeof(int));
 * printf("%d %d", a, b);
 * 
 * Output
 * 6 10
 * -----------------------------------------
 * Sample Code
 * double d = 3.14, f = 1.23567;
 * swap(&d, &f, sizeof(double));
 * printf("%.2f %.2f", d, f);
 * 
 * Output
 * 
 */
int main() 
{
    char letter = 'B', symbol = '+';
    swap(&letter, &symbol, sizeof(char));
    printf("%c %c", letter, symbol);
    printf("\n\n");

    //

    int a = 10, b = 6;
    swap(&a, &b, sizeof(int));
    printf("%d %d", a, b);
    printf("\n\n");

    //
    
    double d = 3.14, f = 1.23567;
    swap(&d, &f, sizeof(double));
    printf("%.2f %.2f", d, f);
    printf("\n");

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    if(errno != 0)
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }
    perror(msg);    
    exit(EXIT_FAILURE);
}

void swap_byte_by_byte(void *ptr1, void *ptr2, size_t size)
{
    unsigned char tmp;
    
    size_t i = 0;
    while(i < size)
    {
        tmp = *(unsigned char *)(ptr1 + i);
        *(unsigned char *)(ptr1 + i) = *(unsigned char *)(ptr2 + i);
        *(unsigned char *)(ptr2 + i) = tmp;
        
        i++;
    }
}

void swap(void *ptr1, void *ptr2, size_t size)
{
    void *tmp = malloc(size);
    if(NULL != tmp)
    {
        memcpy(tmp, ptr1, size);
        memcpy(ptr1, ptr2, size);
        memcpy(ptr2, tmp, size);
        
        free(tmp);
    }
}