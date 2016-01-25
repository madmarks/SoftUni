#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 300
#define ARRAY_SIZE 100

int getIndexOfElement(int *, int, int);

/*
 * Problem_08._Iterative_Binary_Search
 * 
 * Binary search works only on sorted collections. It picks the mid element of 
 * the collection and checks if it's equal to the searched element.
 * 
 *   * If it's equal, returns the mid index.
 *   * If it's smaller, cuts the right half of the collection and repeats 
 *     the same step. 
 *   * If it's larger, cuts the left half of the collection and repeats 
 *     the same step.
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
    printf("%d\n", getIndexOfElement(arr, index, element));
    
    return (EXIT_SUCCESS);
}

/* Iterative Binary Search */

int getIndexOfElement(int *arr, int len, int element)
{
    int leftIndex = 0;
    int rightIndex = len - 1;
    int middleIndex;   
    
    do
    {
        middleIndex = (rightIndex - leftIndex)/2 + leftIndex;
        
        if(arr[middleIndex] < element)
        {
            leftIndex = middleIndex + 1;
        }
        else if(arr[middleIndex] > element)
        {
            rightIndex = middleIndex - 1;
        }
        else if(arr[middleIndex] == element)
        {
            return middleIndex;
        }      
    }while((middleIndex != leftIndex) && (middleIndex != rightIndex));
    
    return -1;
}