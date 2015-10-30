#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Problem_02._Linear_Search
 * 
 * Given an array of n integers, write a linear search function that determines 
 * whether a given element exists in the array. On the first line you will 
 * receive the number n. On the second line, there will be nnumbers, space-
 * separated. On the third line, the search number will be given.
 */
int main() 
{
    int n;
    int element;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));
    
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("The search number: ");
    scanf("%d", &element);
    
    _Bool isFound = false;
    for(i = 0; i < n; i++)
    {
        if(element == arr[i])
        {
            isFound = true;
            break;
        }
    }
    
    printf("\n Output \n");
    printf("%s\n", isFound ? "yes" : "no");
    
    free(arr);

    return (EXIT_SUCCESS);
}

