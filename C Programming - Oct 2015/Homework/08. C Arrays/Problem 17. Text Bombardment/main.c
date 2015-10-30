#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 1001

void error(char *);
int fillMatrixTwoDimensionsFromString(char ***, int, int, char *, int);
int getColumns(int **, int *);

/*
 * Problem_17._Text_Bombardment
 * 
 * Write a program that reads a text and line width from the console. 
 * The program should distribute the text so that it fits in a table with a 
 * specific line width. Each cell should contain only 1 character. It should 
 * then read a line with numbers, holding the columns that should be bombarded. 
 * 
 * For example, we read the text "Well this problem is gonna be a ride." and 
 * line width 10. We distribute the text among 4 rows with 10 columns. We read 
 * the numbers "1 3 7 9" and drop bombs on those columns in the table. The bombs 
 * destroy the character they fall on + all the neighboring characters below it. 
 * 
 * Note: Empty spaces below destroyed characters stop the bombs (see column 7).
 * 
 * Finally, we print the bombarded text on the console:
 * "W l  th s p o lem i   o na be a r de."
 * 
 * Note: The empty cells in the table after the text should NOT be printed.
 * 
 * InputThe input data is read from the console. 
 *   * On the first line you will be given the text
 *   * On the next lines you will be given the line width
 *   * On the third line you will receive the columns that should be 
 *     bombed (space-separated)
 * The input data will always be valid and in the format described. There is no 
 * need to check it explicitly.
 * 
 * Output
 * The output data must be printed on the console and should contain only 
 * 1 line: the bombarded text as a single string. 
 * 
 * Constraints
 *   * The text will contain only ASCII characters and will be no longer than 
 *     1000 symbols.
 *   * The line width will be in the range [1...100].
 *   * The columns will be valid integers in the range [1...<line width> -1].
 *   * A column will not be bombed more than once.
 *   * Time limit: 0.25 seconds. Allowed memory: 16MB.
 * 
 * Example
 * 
 * Input
 * Well this problem is gonna be a ride.
 * 10
 * 1 3 7 9
 * 
 * Output
 * W l  th s p o lem i   o na be a r de.
 */
int main() 
{
    int i, j;
    int lineWidth;
    char buffer[BUFFER_LENGTH];
    
    /* Text */
    
    printf("Input text:");    
    if(NULL == fgets(buffer, BUFFER_LENGTH, stdin))
    {
        error("fgets\n");
    }
    
    int textLen = strlen(buffer);
    if(buffer[textLen - 1] == '\n')
        buffer[textLen - 1] = '\0';
    
    textLen = strlen(buffer); // length of text with '\0'
    
    /* Line width */
    
    printf("Input line width: ");
    scanf("%d", &lineWidth);
    
    if(1 > lineWidth || lineWidth > 100)
    {
        error("Invalid line width!\n");
    }
    
    int rows = (textLen % lineWidth == 0) ? (textLen / lineWidth) 
        : (textLen / lineWidth) + 1;
    
    int cols = lineWidth;
    
    char **arr = NULL;
    if(-1 == fillMatrixTwoDimensionsFromString(&arr, rows, cols, buffer, textLen - 1))
    {
        error("Error when fill matrix!\n");
    }
    
    /* Columns that should be bombarded */
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Input columns that should be bombarded: ");
    
    int *columns = NULL;
    int numOfColumns = lineWidth;
    if(-1 == getColumns(&columns, &numOfColumns))
    {
        error("Error when fill matrix!\n");
    }
    
    for(i = 0; i < numOfColumns; i++)
    {
        if(1 > columns[i] || columns[i] > (lineWidth - 1))
        {
            error("Invalid column that should be bombarded!\n");
        }
    }
    
    /* Text Bombardment */
    
    int column;        
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < numOfColumns; j++)
        {
            column = columns[j]; 
            if(column != -1)
            {
                if(arr[i][column] != 0x20)
                {
                    arr[i][column] = 0x20;
                }

                if((i + 1) < rows && arr[i + 1][column] == 0x20)
                {
                    columns[j] = -1;
                }
            }
        }
    }  
    
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%c", arr[i][j]);
        }
    }
    printf("\n");
    
    /* Free allocated memory */
    
    for(i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    free(columns);

    return (EXIT_SUCCESS);
}

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int fillMatrixTwoDimensionsFromString(char ***arr, int rows, int cols, 
        char *str, int len)
{
    int i, j;
    
    *arr = (char **)malloc(rows * sizeof(char *));
    if(NULL == *arr)
    {
        return -1;
    }
    
    for(i = 0; i < rows; i++)
    {
        (*arr)[i] = (char *)calloc(cols, sizeof(char)); // fill with 0's
        if(NULL == (*arr)[i])
        {
            return -1;
        }
    }
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if((i * cols + j) <= len)
                (*arr)[i][j] = str[i * cols + j];
            else
                (*arr)[i][j] = 0x20; // add space
        }
    }
}

int getColumns(int **columns, int *numOfColumns)
{
    int i;
    char buffer[BUFFER_LENGTH];
    
    *columns = (int *)malloc(*numOfColumns * sizeof(int));
    if(NULL == *columns)
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

        (*columns)[index++] = val;

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

            (*columns)[index++] = val;
        }
    }
    
    *numOfColumns = index;
    int *newColumns = (int *)realloc(*columns, *numOfColumns * sizeof(int));
    if(NULL != newColumns)
    {
        *columns = newColumns;
    }
}