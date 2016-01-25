#include <stdio.h>
#include <stdlib.h>

int *removeDuplicates(int *, int, int *);

/*
 * Problem_06._Join_Lists
 * 
 * Write a program that takes as input two arrays of integers and joins them. 
 * The result should hold all numbers from the first array, and all numbers from 
 * the second array, without repeating numbers, and arranged in increasing 
 * order. On the first input line, you are given the count of the elements of 
 * the first array. On the next line you are given the length of the second array. 
 */
int main() 
{
    int n1;
    int n2;
    int i, j, tmp;
    
    printf("Length of first array = ");
    scanf("%d", &n1);
    printf("Length of second array = ");
    scanf("%d", &n2);
    
    int *arr = malloc((n1 + n2) * sizeof(int));

    for(i = 0; i < (n1 + n2); i++)
    {
        scanf("%d", &arr[i]);
    }   
    
    int newLen;
    int *arrWithoutDuplicates = removeDuplicates(arr, n1 + n2, &newLen);
    
    printf("\n Output\n");
    for(i = 0; i < newLen; i++)
    {
        printf("%d ", arrWithoutDuplicates[i]);
    }
    printf("\n");
    
    free(arr);
    free(arrWithoutDuplicates);

    return (EXIT_SUCCESS);
}

int *removeDuplicates(int *arr, int len, int *newLen)
{
    int i, j, tmp;
    
    /* Sort array */
    
    for(i = 0; i < len - 1; i++)
    {
        for(j = 1; j < len - i; j++)
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
    
    int countDuplicates = 0;
    for(i = 1; i < len; i++)
    {
        if(arr[i] == arr[i - 1])
        {
            countDuplicates++;
        }
    }
    
    *newLen = len - countDuplicates;
    int *newArr = malloc((*newLen) * sizeof(int));
    
    int idx = 1;
    newArr[0] = arr[0];
    for(i = 1; i < len; i++)
    {
        if(arr[i] != arr[i - 1])
        {
            newArr[idx++] = arr[i];
        }
    }
    
    return newArr;
}