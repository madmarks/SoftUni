#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Problem 09. Matrix of Numbers
 * 
 * Write a program that reads from the console a positive integer number n
 * (1 <= n <= 20) and prints a matrix like in the examples below.
 * Use two nested loops. 
 * 
 * | n | matrix |     | n | matrix |     | n |  matrix |
 * |   |        |     |   |        |     |   | 1 2 3 4 |
 * | 2 |   1 2  |     | 3 |  1 2 3 |     | 4 | 2 3 4 5 |
 * |   |   2 3  |     |   |  2 3 4 |     |   | 3 4 5 6 |
 * |   |        |     |   |  3 4 5 |     |   | 4 5 6 7 |
 */
int main() 
{
    int n;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    int titleLen = strlen("matrix");
    int colWidth = 3;
    int rowWidth = n * colWidth;
    
    int numSpacesAfter = rowWidth > titleLen ? (rowWidth - titleLen)/2 : 0;
    int numSpacesBefore = numSpacesAfter;
    if((rowWidth > titleLen) && ((rowWidth - titleLen) % 2) != 0)
    {
        numSpacesBefore++;
    }
    
    printf("\n|  n | %*s%s%*s |\n", numSpacesBefore, "", "matrix", 
        numSpacesAfter, "");
    
    int i, j;
    char buf[20];
    for(i = 1; i <= n; i++)
    {
        printf("| %2s | ", (i == 1) ? sprintf(buf, "%2d", n), buf : "");
        for(j = i; j < i + n; j++)
        {
            printf("%2d ", j);
        }
        printf(" |\n");
    }    

    return (EXIT_SUCCESS);
}

