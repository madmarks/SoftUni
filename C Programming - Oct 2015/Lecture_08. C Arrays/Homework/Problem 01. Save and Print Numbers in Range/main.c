#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 01. Save and Print Numbers in Range
 * 
 * Write a program that reads n numbers from the console and saves them in an 
 * array. The program should then print the elements of the array on the console.
 */
int main() 
{
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));
    
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\n Output \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return (EXIT_SUCCESS);
}

