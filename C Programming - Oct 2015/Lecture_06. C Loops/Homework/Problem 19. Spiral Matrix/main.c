#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * Problem 19. Spiral Matrix
 * 
 * Write a program that reads from the console a positive integer number n
 * (1 <= n <= 20) and prints a matrix holding the numbers from 1 to n*n in 
 * the form of square spiral like in the examples below. 
 * 
 * | n | matrix |     | n | matrix |     | n |    matrix   |
 * |   |        |     |   |        |     |   |  1  2  3  4 |
 * | 2 |   1 2  |     | 3 |  1 2 3 |     | 4 | 12 13 14  5 |
 * |   |   4 3  |     |   |  8 9 4 |     |   | 11 16 15  6 |
 * |   |        |     |   |  7 6 5 |     |   | 10  9  8  7 |
 */
int main() 
{
    int i, j;
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    int **arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        memset(arr[i], 0, n * sizeof(int));
    }
    
    int row = 0;
    int col = 0;
    
    int rowDir = 0;
    int colDir = 1;
    
    i = 1;
    while(i <= n*n)
    {
        arr[row][col] = i;
        
        if(rowDir == 0 && colDir == 1)
        {
            if((col + colDir) >= n || arr[row][col + colDir] > 0)
            {
                rowDir = 1;
                colDir = 0;
            }
        }        
        else if(rowDir == 1 && colDir == 0)
        {
            if((row + rowDir) >= n || arr[row + rowDir][col] > 0)
            {
                rowDir = 0;
                colDir = -1;
            }
        }
        else if(rowDir == 0 && colDir == -1)
        {
            if((col + colDir) < 0 || arr[row][col + colDir] > 0)
            {
                rowDir = -1;
                colDir = 0;
            }
        }
        else if(rowDir == -1 && colDir == 0)
        {
            if((row + rowDir) < 0 || arr[row + rowDir][col] > 0)
            {
                rowDir = 0;
                colDir = 1;
            }
        }
        
        row += rowDir;
        col += colDir;
        i++;
    }
    
    /* Print spiral matrix */
    
    int titleLen = strlen("matrix");
    int colWidth = 4;
    int rowWidth = n * colWidth;
    
    int numSpacesAfter = rowWidth > titleLen ? (rowWidth - titleLen)/2 : 0;
    int numSpacesBefore = numSpacesAfter;
    if((rowWidth > titleLen) && ((rowWidth - titleLen) % 2) != 0)
    {
        numSpacesBefore++;
    }
    
    printf("\n|  n | %*s%s%*s |\n", numSpacesBefore, "", "matrix", 
        numSpacesAfter, "");
    
    char buf[20];
    for(i = 0; i < n; i++)
    {
        printf("| %2s | ", (i == 0) ? sprintf(buf, "%2d", n), buf : "");
        for(j = 0; j < n; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf(" |\n");
    }    
    
    /* Free allocated memory */   
    
    for(i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    
    return (EXIT_SUCCESS);
}

