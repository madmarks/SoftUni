#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 300

/*
 * Problem_10._Numbers_Beneath_Main_Diagonal
 * 
 * You are given a matrix of numbers. Your task is to print out the numbers, 
 * one group at a line, which are stationed beneath the matrix’s main diagonal 
 * along with the diagonal itself. On the first input line, you are given 
 * the matrix’s rows and cols count.
 */
int main() 
{
    int n;
    int i, j;
    char buffer[BUFFER_LENGTH];
    
    printf("Length of array = ");
    scanf("%d", &n);
    
    int **arr = malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = malloc(n * sizeof(int));
    }
    
    int val;
    char *endPtr;
    char *token;
    const char *delimiters = ", ";
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    for(i = 0; i < n; i++)
    {            
        fgets(buffer, BUFFER_LENGTH, stdin);

        int length = strlen(buffer);
        if (buffer[length - 1] == '\n')
            buffer[length - 1] = '\0';
        
        int index = 0;

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

            arr[i][index++] = val;

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

                arr[i][index++] = val;
            }
        }       
    }
    
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return (EXIT_SUCCESS);
}

