#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH 1001

void error(char *);
int fillMatrixTwoDimensionsFromString(char ***, int, int, char *, int);

/*
 * Problem_16._Text_Gravity
 * 
 * Write a program that takes as input a line length and text and formats 
 * the text so that it fits inside several rows, each with length equal to 
 * the given line length. Once the text is fitted, each character starts 
 * dropping as long as there is an empty space below it. For example, we are 
 * given the text "The Milky Way is the galaxy that contains our star system" 
 * and line length of 10. If we distribute the text characters such that 
 * the text fits in lines with length 10, the result is:
 * 
 * 
 * 
 * 
 * Text characters start 'falling' until no whitespace remain under any 
 * character. The resulting text should be printed in a table manner as shown 
 * below.
 * 
 * Input
 * 
 * The input will come from the console. It will consist of two lines.
 *   * The first line will hold the line length.
 *   * The second input line will hold a string.
 * 
 * Output
 * 
 * The output consists of lines, enclosed in pipe characters ('|'). Print 
 * space " " in all empty cells. See the example below.
 * 
 * Constraints
 *   * The line length will be an integer in the range [1 ... 30].
 *   * The text will consist of [1 ... 1000] ASCII characters.
 * 
 * Example
 * 
 * Input
 * 10 
 * The Milky Way is the galaxy that contains our star system
 * 
 * Output
 * |    M     |
 * | he iil y |
 * |Taylasykhe|
 * |Wgacoxttth|
 * |atournsain|
 * |ssystemtar|
 */
int main() 
{
    int i, j;
    int lineLength;
    char buffer[BUFFER_LENGTH];
    
    printf("Input line length: ");
    scanf("%d", &lineLength);
    
    if(1 > lineLength || lineLength > 30)
    {
        error("Invalid line length!\n");
    }
    
    // flush stdin because of unread newline or other unexpected 
    // input after calling scanf 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("Input text:");    
    if(NULL == fgets(buffer, BUFFER_LENGTH, stdin))
    {
        error("fgets\n");
    }
    
    int len = strlen(buffer);
    if(buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    
    len = strlen(buffer);
    
    int rows = 
        (len % lineLength == 0) ? (len / lineLength) : (len / lineLength) + 1;
    
    int cols = lineLength;
    
    char **arr = NULL;
    if(-1 == fillMatrixTwoDimensionsFromString(&arr, rows, cols, buffer, len - 1))
    {
        error("Error when fill matrix!\n");
    }
    
    /* Text gravity */
    
    _Bool hasChange = true;
    while(hasChange)
    {
        hasChange = false;
        
        for(i = rows - 1; i >= 1; i--)
        {
            for(j = 0; j < cols; j++)
            {
                if(arr[i][j] == 0x20 && arr[i - 1][j] != 0x20)
                {
                    // swap
                    arr[i][j] += arr[i - 1][j];
                    arr[i - 1][j] = arr[i][j] - arr[i - 1][j];
                    arr[i][j] = arr[i][j] - arr[i - 1][j];
                    
                    hasChange = true;
                }
            }
        }
    }
    
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < rows; i++)
    {
        printf("|");
        for(j = 0; j < cols; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("|\n");
    }
    
    /* Free allocated memory */
    
    for(i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    
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