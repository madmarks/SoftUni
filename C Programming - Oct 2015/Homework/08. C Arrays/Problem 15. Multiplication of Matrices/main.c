#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 300

int fillMatrixTwoDimensions(int ***, int, int);
void multiplicationTwoMatrices(int **, int, int, int **, int, int, int **);

/*
 * Problem_15._Multiplication_of_Matrices
 * 
 * A multiplication of two matrices is performed by taking each of the rows of 
 * the first matrix and taking the dot product of it and each of the columns in 
 * the second matrix. The newly created matrix has dimensions RxC, where R is 
 * the number of rows of the first matrix and C is the number of columns of 
 * the second matrix. 
 * 
 * Note that a matrix multiplication is valid only if the number of rows of 
 * the first matrix is equal to the number of columns of the second matrix and 
 * the number of columns of the first one are equal to the number of rows of 
 * the second one. Example:
 * 
 * |a1, a2, a3|   |b1, b2|   |(a1*b1+ a2*b4+ a3*b7) , (a1*b2+ a2*b5+ a3*b8)|      
 * |a4, a5, a6| x |b4, b5| = |(a4*b1+ a5*b4+ a6*b7) , (a4*b2+ a5*b5+ a6*b8)|
 *                |b7, b8|
 * 
 * On the first two input lines you are given the dimensions of the first 
 * matrix. The second matrix has the same dimensions in inversed order. 
 */
int main() 
{
    int i, j;
    int rows;
    int cols;
    
    printf("Input rows = ");
    scanf("%d", &rows);
    printf("Input columns = ");
    scanf("%d", &cols);
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    int rowsMatrix1 = rows;
    int colsMatrix1 = cols;
    int **matrix1 = NULL;
    if(-1 == fillMatrixTwoDimensions(&matrix1, rowsMatrix1, colsMatrix1))
    {
        return (EXIT_FAILURE);
    }
    
    int rowsMatrix2 = cols;
    int colsMatrix2 = rows;
    int **matrix2 = NULL;
    if(-1 == fillMatrixTwoDimensions(&matrix2, rowsMatrix2, colsMatrix2))
    {
        return (EXIT_FAILURE);
    }
    
    int **resMatrix = NULL;
    
    resMatrix = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++)
    {
        resMatrix[i] = (int *)malloc(cols * sizeof(int));
    }
    
    /* Multiplying matrix1 and matrix2 and storing result in resMatrix. */
    
    multiplicationTwoMatrices(matrix1, rowsMatrix1, colsMatrix1, 
            matrix2, rowsMatrix2, colsMatrix2, resMatrix);
    
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < rowsMatrix1; i++)
    {
        for(j = 0; j < colsMatrix2; j++)
        {
            printf("%d ", resMatrix[i][j]);
        }
        printf("\n");
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < rowsMatrix1; i++)
    {
        free(matrix1[i]);
        free(resMatrix[i]);
    }
    for(i = 0; i < rowsMatrix2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resMatrix);
    
    return (EXIT_SUCCESS);
}

int fillMatrixTwoDimensions(int ***arr, int rows, int cols)
{
    int i;
    char buffer[BUFFER_LENGTH];
    
    *arr = (int **)malloc(rows * sizeof(int *));
    if(NULL == *arr)
    {
        return -1;
    }
    
    for(i = 0; i < rows; i++)
    {
        (*arr)[i] = (int *)malloc(cols * sizeof(int));
        if(NULL == (*arr)[i])
        {
            return -1;
        }
    }
    
    int val;
    char *endPtr;
    char *token;
    const char *delimiters = ", ";
    
    for(i = 0; i < rows; i++)
    {
        if(NULL == fgets(buffer, BUFFER_LENGTH, stdin))
        {
            return -1;
        }

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
                return -1;
            }

            if (endPtr == buffer) 
            {
                fprintf(stderr, "No digits were found\n");
                return -1;
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
                    return -1;
                }

                if (endPtr == buffer) 
                {
                    fprintf(stderr, "No digits were found\n");
                    return -1;
                }

                if(index < cols)
                {
                    (*arr)[i][index++] = val;
                }
            }
        }       
    } 
}

void multiplicationTwoMatrices(int **a, int rowsA, int colsA, 
        int **b, int rowsB, int colsB, int **res)
{
    int i, j, k;
    int sum = 0;
    
    for(i=0; i < rowsA; ++i)
    {
        for(j=0; j < colsB; ++j)
        {
            for(k=0; k < colsA; ++k)
            {
                sum += a[i][k] * b[k][j];
            }
            
            res[i][j] = sum;
            sum = 0;
        }
    }
}