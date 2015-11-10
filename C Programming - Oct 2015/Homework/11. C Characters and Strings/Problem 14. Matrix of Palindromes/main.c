#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 14. Matrix of Palindromes
 * 
 * Write a program to generate the following matrix of palindromes of 3 letters 
 * with r rows and c columns
 * 
 * ----------------------------------------------------------------------------
 *     Input    |          Output
 * ----------------------------------------------------------------------------
 *              | aaa aba aca ada aea afa
 *   3  6       | bbb bcb bdb beb bfb bgb
 *              | ccc cdc cec cfc cgc chc
 * ----------------------------------------------------------------------------
 *   2  3       | aaa aba aca
 *              | bbb bcb bdb
 * ----------------------------------------------------------------------------
 *   1  1       | aaa
 * ----------------------------------------------------------------------------
 *   1  3       | aaa aba aca
 * ----------------------------------------------------------------------------
 */
int main() 
{
    int i, j;
    int rows;
    int cols;
    
    printf("Rows: ");
    scanf("%3d", &rows);
    
    printf("\nColumns: ");
    scanf("%3d", &cols);    
    
    printf("\n Output\n");
    for(i = 0; i < rows; i++)
    {
        for(j = i; j < i + cols; j++)
        {
            printf("%c", 97 + i);
            printf("%c", 97 + j);
            printf("%c ", 97 + i);
        }
        printf("\n");
    }    

    return (EXIT_SUCCESS);
}

