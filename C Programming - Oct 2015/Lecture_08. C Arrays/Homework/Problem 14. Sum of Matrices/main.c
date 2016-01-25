#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 300

int fillMatrixTwoDimensions(int ***, int, int);

/*
 * Problem_14._Sum_of_Matrices
 * 
 * You are given two matrices and you have to output a new matrix which is their 
 * sum. The sum of matrices is calculated by adding each of the members from the 
 * first matrix with each of the members of the second one and producing a number 
 * which is a member of a new matrix and is stationed in the same row and col. 
 * Write a program to calculate the sum of two matrices. On the first 2 lines, 
 * you are given the dimensions of the two matrices (In order for them to be 
 * added together, they must be of the same dimensions). The first line 
 * represents the rows of the matrices and the second one - the columns. 
 * On the next input lines, you are given the members of the matrices. 
 */
int main() 
{
    int i, j;
    int matrixRows;
    int matrixCols;
    
    printf("Input rows = ");
    scanf("%d", &matrixRows);
    printf("Input columns = ");
    scanf("%d", &matrixCols);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    int **matrix1 = NULL;
    fillMatrixTwoDimensions(&matrix1, matrixRows, matrixCols);
    
    int **matrix2 = NULL;
    fillMatrixTwoDimensions(&matrix2, matrixRows, matrixCols);
      
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < matrixRows; i++)
    {
        for(j = 0; j < matrixCols; j++)
        {
            printf("%d ", matrix1[i][j] + matrix2[i][j]);
        }
        printf("\n");
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < matrixRows; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    return (EXIT_SUCCESS);
}

int fillMatrixTwoDimensions(int ***arr, int rows, int cols)
{
    int i;
    char buffer[BUFFER_LENGTH];
    
    *arr = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++)
    {
        (*arr)[i] = (int *)malloc(cols * sizeof(int));
    }
    
    int val;
    char *endPtr;
    char *token;
    const char *delimiters = ", ";
    
    for(i = 0; i < rows; i++)
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

            if(index < cols)
            {
                (*arr)[i][index++] = val;
            }

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

                if(index < cols)
                {
                    (*arr)[i][index++] = val;
                }
            }
        }       
    } 
}