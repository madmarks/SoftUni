#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *, int);

/*
 * Problem_07._Reverse_Array
 * 
 * Write a program that reverses an array of numbers. The numbers should be 
 * entered one at a line. On the first input line you will be given the count of 
 * the numbers.
 */
int main() 
{
    int n;
    int i;
    
    printf("Length of array = ");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    } 
    
    reverseArray(arr, n);
    
    printf("\n Output\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return (EXIT_SUCCESS);
}

void reverseArray(int *arr, int len)
{
    int i, tmp;
    
    for(i = 0; i < len/2; i++)
    {
        // swap them
        tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}