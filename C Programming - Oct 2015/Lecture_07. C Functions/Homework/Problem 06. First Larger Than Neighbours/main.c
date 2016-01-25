#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

int firstLargerThanNeighboursInt(int *, int);
int firstLargerThanNeighboursChar(char *, int, const char *);
int *stringOfIntNumbersToArrayOfInts(char *, int *, const char *);

/*
 * Problem 6. First Larger Than Neighbours
 * 
 * Write a method that returns the index of the first element in array that is 
 * larger than its neighbours, or -1 if there's no such element. 
 * Declare a function prototype before defining the function.
 */
int main() 
{
    // delimiters
    const char *delimiters = ", ";
    
    char buffer[BUFFER_LENGTH];
    printf("Input elements of array: ");
    fgets(buffer, BUFFER_LENGTH, stdin);
    
    int length = strlen(buffer);
    if(buffer[length -1] == '\n')
        buffer[length -1] = '\0';
    
//    printf("\nReturn value: %i\n", 
//        firstLargerThanNeighboursChar(buffer, length, delimiters));
    
    int *arr = stringOfIntNumbersToArrayOfInts(buffer, &length, delimiters);
    if(arr != NULL)
    {
        printf("\nReturn value: %i\n", 
            firstLargerThanNeighboursInt(arr, length));
    }

    return (EXIT_SUCCESS);
}

int firstLargerThanNeighboursInt(int *arr, int len)
{
    int i;
    for(i = 1; i < len - 1; i++)
    {
        if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    
    return -1;
}

int firstLargerThanNeighboursChar(char *buffer, int length, 
    const char *delimiters)
{
    int previous;
    int current;
    int next;
    char *token;
    
    // it is need because strtok() modifies char array
    char *bufferCopy = malloc(length);
    strcpy(bufferCopy, buffer);
    
    /* get the first token */
    if(NULL != (token = strtok(bufferCopy, delimiters)))
    {
        previous = atoi(token);
        int index = 0;
        
        if(NULL != (token = strtok(NULL, delimiters)))
        {
            current = atoi(token);
            index++;
            
            /* walk through other tokens */
            while(NULL != (token = strtok(NULL, delimiters))) 
            {
                next = atoi(token);
                
                if(previous < current && current > next)
                {
                    return index;
                }
                
                previous = current;
                current = next;
                index++;
            }
        }
    }
    
    return -1;
}

int *stringOfIntNumbersToArrayOfInts(char *buffer, int *length, 
        const char *delimiters)
{
    // it is need because strtok() modifies char array
    char *bufferCopy_1 = malloc(*length);
    strcpy(bufferCopy_1, buffer);
    
    char *bufferCopy_2 = malloc(*length);
    strcpy(bufferCopy_2, buffer);
     
    // count of array elements
    int count = 0;
    char *token; 
    
    // count number of tokens
    // 1 2 3 4 5 6 7 8 9, 1 ,1 -> 8
    /* get the first token */
    if(NULL != (token = strtok(bufferCopy_1, delimiters)))
    {
        count++;

        while(NULL != (token = strtok(NULL, delimiters))) 
        {
            count++;
        }
    }
    
    int i = 0;
    int *arr = malloc(count * sizeof(int));
    
    /* get the first token */
    if(NULL != (token = strtok(bufferCopy_2, delimiters)))
    {
        arr[i++] = atoi(token);

        while(NULL != (token = strtok(NULL, delimiters))) 
        {
            arr[i++] = atoi(token);
        }
    }
    
    free(bufferCopy_1);
    free(bufferCopy_2);
    
    *length = count;
    return arr;
}