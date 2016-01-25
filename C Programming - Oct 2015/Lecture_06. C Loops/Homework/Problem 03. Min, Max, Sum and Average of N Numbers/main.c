#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

/*
 * Problem 3. Min, Max, Sum and Average of N Numbers
 * 
 * Write a program that reads from the console a sequence of n integer 
 * numbers and returns the minimal, the maximal number, the sum and 
 * the average of all numbers (displayed with 2 digits after the decimal point).
 * The input starts by the number n (alone in a line) followed by n lines, 
 * each holding an integer number.
 */
int main() 
{
    int n;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    float avg;

    printf("Input n = ");
    scanf("%d", &n);

    if (n > 0) 
    {        
        int *nums = malloc(n * sizeof(int));

        int i;
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &nums[i]);

            if (nums[i] < min)
                min = nums[i];

            if (nums[i] > max)
                max = nums[i];

            sum += nums[i];
        }

        char buffer[10];
        printf("\n| input | output\n");
        printf("| %5d | min = %.2f\n", n, (float)min);
        printf("| %5d | max = %.2f\n", nums[0], (float)max);
        printf("| %5s | sum = %.2f\n", 
            n > 1 ? sprintf(buffer, "%d", nums[1]), buffer : "", (float)sum);
        printf("| %5s | avg = %.2f\n", 
            n > 2 ? sprintf(buffer, "%d", nums[2]), buffer : "", (float)sum/n);
        
        for(i = 3; i < n; i++)
        {
            printf("| %5d |\n", nums[i]);
        }

        free(nums);
    }
    else
    {
        printf("Wrong input!");
    }

    return (EXIT_SUCCESS);
}

