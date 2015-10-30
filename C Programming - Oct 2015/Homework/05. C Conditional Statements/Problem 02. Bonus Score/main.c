#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 02. Bonus Score
 * 
 * Write a program that applies bonus score to given score in the 
 * range [1...9] by the following rules:
 * 
 *   * If the score is between 1 and 3, the program multiplies it by 10.
 *   * If the score is between 4 and 6, the program multiplies it by 100.
 *   * If the score is between 7 and 9, the program multiplies it by 1000.
 *   * If the score is 0or more than 9, the program prints "invalid score".
 */
int main() 
{
    int score;
    int result;
    
    printf("Input score = ");
    scanf("%d", &score);
    
    printf("\n| score |     result    |\n");
    printf("|  %3d  | ", score);
    
    if(1 <= score && score <= 3)
    {
        printf("%-13d |\n", score * 10);
    }
    else if(4 <= score && score <= 6)
    {
        printf("%-13d |\n", score * 100);
    }
    else if(7 <= score && score <= 9)
    {
        printf("%-13d |\n", score * 1000);
    }
    else
    {
        printf("invalid score |\n");
    }   
    
    return (EXIT_SUCCESS);
}

