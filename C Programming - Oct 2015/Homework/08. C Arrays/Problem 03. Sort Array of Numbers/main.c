#include <stdio.h>
#include <stdlib.h>

/*
 * Problem_03._Sort_Array_of_Numbers
 * 
 * Write a program to read an array of numbers from the console, sort them and 
 * print them back on the console. Use a sorting algorithm of your choosing.
 * The numbers should be entered one at a line. On the first input line you 
 * will be given the count of the numbers. 
 */
int main() 
{
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));
    
    int i, j, tmp;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Sort array */
    
    for(i = 0; i < n - 1; i++)
    {
        for(j = 1; j < n - i; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                // swap them
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
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