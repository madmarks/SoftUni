#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 300
#define ARRAY_SIZE 100

int getIndexOfElementRecursive(int *, int, int, int);

/*
 * Problem_09._Recursive__Binary_Search
 * 
 * Implement binary search using recursion. You are not allowed to use loops.
 */
int main() 
{
    int element;
    int val;
    char *endPtr;

    char buffer[BUFFER_LENGTH];
    int arr[ARRAY_SIZE];
    
    printf("Array = ");

    fgets(buffer, BUFFER_LENGTH, stdin);

    int length = strlen(buffer);
    if (buffer[length - 1] == '\n')
        buffer[length - 1] = '\0';

    int index = 0;
    char *token;
    const char *delimiters = ", ";

    /* get the first token */
    if (NULL != (token = strtok(buffer, delimiters))) 
    {
        /* To distinguish success/failure after call */
        errno = 0;

        val = strtol(token, &endPtr, 10);

        /* Check for various possible errors */

        if ((errno == ERANGE && (val == INT_MAX || val == INT_MIN))
                || (errno != 0 && val == 0)) 
        {
            perror("strtol");
            return (EXIT_FAILURE);
        }

        if (endPtr == buffer) 
        {
            fprintf(stderr, "No digits were found\n");
            return (EXIT_FAILURE);
        }

        arr[index++] = val;

        /* walk through other tokens */
        while (NULL != (token = strtok(NULL, delimiters))) 
        {
            /* To distinguish success/failure after call */
            errno = 0;

            val = strtol(token, &endPtr, 10);

            /* Check for various possible errors */

            if ((errno == ERANGE && (val == INT_MAX || val == INT_MIN))
                    || (errno != 0 && val == 0)) 
            {
                perror("strtol");
                return (EXIT_FAILURE);
            }

            if (endPtr == buffer) 
            {
                fprintf(stderr, "No digits were found\n");
                return (EXIT_FAILURE);
            }

            arr[index++] = val;
        }
    }

    printf("Searched element = ");
    scanf("%d", &element);

    printf("\n Output\n");
    printf("%d\n", getIndexOfElementRecursive(arr, 0, index - 1, element));
    
    return (EXIT_SUCCESS);
}

int getIndexOfElementRecursive(int *arr, int leftIdx, int rightIdx, int element)
{
    int middleIdx; 

    if(leftIdx == rightIdx)
    {
        if(arr[leftIdx] == element)
        {
            return leftIdx;
        }
        else
        {
            return -1;
        }
    }
    
    //middleIdx = (rightIdx - leftIdx)/2 + leftIdx;
    middleIdx = rightIdx - (rightIdx - leftIdx)/2;

    if(arr[middleIdx] < element)
    {
        return getIndexOfElementRecursive(arr, 
            middleIdx + 1, rightIdx, element);
    }
    else if(arr[middleIdx] > element)
    {
        return getIndexOfElementRecursive(arr, 
            leftIdx, middleIdx - 1, element);
    }        
    else if(arr[middleIdx] == element)
    {
        return middleIdx;
    }        
}