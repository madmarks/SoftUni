#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>


/*
 * Problem_04._Categorize_Numbers_and_Find_Min_Max_Average
 * 
 * Write a program that reads N floating-point numbers from the console. Your 
 * task is to separate them in two sets, one containing only the round numbers
 * (e.g. 1, 1.00, etc.) and the other containing the floating-point numbers with 
 * non-zero fraction. Print both arrays along with their minimum, maximum, 
 * sum and average (rounded to two decimal places). The numbers should be 
 * entered one at a line. On the first input line you will be given the count of 
 * the numbers. 
 */
int main() 
{
    int n;
    int countRoundNumbers = 0;
    int countNonRoundNumbers = 0;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    float *arr = malloc(n * sizeof(float));
    
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
        
        if(fabs(fmod(arr[i], 1)) > 0)
        {
            countNonRoundNumbers++;
        }
        else
        {
            countRoundNumbers++;
        }
    }
    
    float *roundNumbers = malloc(countRoundNumbers * sizeof(float));
    float *nonRoundNumbers = malloc(countNonRoundNumbers * sizeof(float));
    
    float minOfRoundNumbers = FLT_MAX;
    float minOfNonRoundNumbers = FLT_MAX;
   
    float maxOfRoundNumbers = FLT_MIN;
    float maxOfNonRoundNumbers = FLT_MIN;
    
    double sumOfRoundNumbers = 0;
    double sumOfNonRoundNumbers = 0;
    
    int nonRound = 0;
    int round = 0;
    for(i = 0; i < n; i++)
    {
        if(fabs(fmod(arr[i], 1)) > 0)
        {
            nonRoundNumbers[nonRound++] = arr[i];
            sumOfNonRoundNumbers += arr[i];
            
            if(minOfNonRoundNumbers > arr[i])
            {
                minOfNonRoundNumbers = arr[i];
            }
            
            if(maxOfNonRoundNumbers < arr[i])
            {
                maxOfNonRoundNumbers = arr[i];
            }
        }
        else
        {
            roundNumbers[round++] = arr[i];
            sumOfRoundNumbers += arr[i];
            
            if(minOfRoundNumbers > arr[i])
            {
                minOfRoundNumbers = arr[i];
            }
            
            if(maxOfRoundNumbers < arr[i])
            {
                maxOfRoundNumbers = arr[i];
            }
        }        
    }
    
    if(countNonRoundNumbers > 0)
    {
        printf("\n[%.3f", nonRoundNumbers[0]);
        for(i = 1; i < countNonRoundNumbers; i++)
        {
            printf(", %.3f", nonRoundNumbers[i]);
        }
        printf("] -> min: %.2f, max: %.3f, sum: %.3lf, avg: %.2lf\n",
            minOfNonRoundNumbers, maxOfNonRoundNumbers, 
            sumOfNonRoundNumbers, sumOfNonRoundNumbers/countNonRoundNumbers);
    }
    
    if(countRoundNumbers > 0)
    {
        printf("\n[%.0f", roundNumbers[0]);
        for(i = 1; i < countRoundNumbers; i++)
        {
            printf(", %.0f", roundNumbers[i]);
        }
        printf("] -> min: %.0f, max: %.0f, sum: %.0lf, avg: %.2lf\n",
            minOfRoundNumbers, maxOfRoundNumbers, 
            sumOfRoundNumbers, sumOfRoundNumbers/countRoundNumbers);   
    }
    
    free(nonRoundNumbers);
    free(roundNumbers);
    free(arr);

    return (EXIT_SUCCESS);
}

