#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 21. * Diamond
 * 
 * You are given as input a number which represents the height and width of a 
 * diamond. Your task is to draw it according to the given metrics. See the 
 * examples for clarification.
 * 
 * ----------------------------------------------------------------------------
 *           Input           |            Output
 * ----------------------------------------------------------------------------
 *                           | ..*..
 *                           | .*.*.
 *  5                        | *...*
 *                           | .*.*.
 *                           | ..*..
 * ----------------------------------------------------------------------------
 *                           | ...*...
 *                           | ..*.*..
 *                           | .*...*.
 *  7                        | *.....*
 *                           | .*...*.
 *                           | ..*.*..
 *                           | ...*...
 * ----------------------------------------------------------------------------
 *                           | .*.
 *  3                        | *.*
 *                           | .*.
 * ----------------------------------------------------------------------------
 */
int main() 
{    
    int num;
    
    printf("Input:");
    scanf("%d", &num);
    
    int i, j;
    int modifier;
 
    printf("\n Output\n");

    if(num % 2 == 1)
        modifier = 0;
    else
        modifier = 1;
    
    for(i = 0; i < num; i++)
    {        
        for(j = 0; j < num; j++)
        {
            if(i < num/2)
            {
                if(j == (num/2 - i - modifier) || j == (num/2 + i))
                    printf("*");
                else
                    printf(".");
            }
            else
            {
                if(j == (i - num/2) || j == (num + num/2 - i - 1))
                    printf("*");
                else
                    printf(".");
            }
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}

