#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define BUFFER_LENGTH 300

void error(char *);
int fillArrayOneDimension(int **, size_t *);

/*
 * Problem 03. Print Array Reversed
 * 
 * You are given a sample array as input and your task is to print the array in 
 * reversed order using pointer arithmetic instead of indexing.
 */
int main() 
{
    int n;
    
    printf("Input number of array elements: ");
    scanf("%d", &n);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Input array of integers: ");
    
    int *arr = NULL;
    size_t size = -1;
    if(-1 == fillArrayOneDimension(&arr, &size) || size == -1)
    {
        error("Error when fill array of integers!\n");
    }
        
    /* Print result */
    
    size_t i = size;
    printf("\n Output\n");
    while(i > 0)
    {
        i--;
        
        if(i != 0)
            printf("%d, ", *(arr + i));
        else
            printf("%d\n", *arr);
    }
    
    /* Free allocated memory */
    
    free(arr);

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int fillArrayOneDimension(int **arr, size_t *size)
{
    int i;
    char buffer[BUFFER_LENGTH];
    
    // worst scenario -> (BUFFER_LENGTH / 2) , because of delimiters
    *arr = (int *)malloc((BUFFER_LENGTH / 2) * sizeof(int)); 
    if(NULL == *arr)
    {
        return -1;
    }
    
    int val;
    char *endPtr;
    char *token;
    const char *delimiters = ", ";
    
    if(NULL == fgets(buffer, BUFFER_LENGTH, stdin))
    {
        return -1;
    }

    int length = strlen(buffer);
    if (buffer[length - 1] == '\n')
        buffer[length - 1] = '\0';

    int index = -1;

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
            return -1;
        }

        if (endPtr == buffer) 
        {
            fprintf(stderr, "No digits were found\n");
            return -1;
        }

        (*arr)[++index] = val;

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
                return -1;
            }

            if (endPtr == buffer) 
            {
                fprintf(stderr, "No digits were found\n");
                return -1;
            }

            (*arr)[++index] = val;
        }
    }
    
    if(index >= 0)
    {
        *size = ++index;
        
        int *newArr = (int *)realloc(*arr, *size * sizeof(int));
        if(NULL != newArr)
        {
            *arr = newArr;
        }
    }
    else
    {
        *size = -1;
    }   
}