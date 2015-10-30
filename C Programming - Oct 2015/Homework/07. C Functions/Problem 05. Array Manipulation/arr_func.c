#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "arr_func.h"

double arr_min(double *arr, int len)
{
    int i;
    double min = arr[0];
    
    for(i = 1; i < len; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    
    return min;
}

double arr_max(double *arr, int len)
{
    int i;
    double max = arr[0];
    
    for(i = 1; i < len; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    
    return max;
}

void arr_clear(double *arr, int len)
{
    int i;
    
    for(i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
}

double arr_average(double *arr, int len)
{
    return arr_sum(arr, len)/(double)len;
}

double arr_sum(double *arr, int len)
{
    int i;
    double sum = 0.0;
    
    for(i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    
    return sum;
}

_Bool arr_contains(double *arr, int len, double element)
{
    int i;
    
    for(i = 0; i < len; i++)
    {
        if(arr[i] == element)
        {
            return true;
        }
    }
    
    return false;
}

double *arr_merge(double *arr1, int len1, double *arr2, int len2)
{
    int i;
    double *arr = (double *)malloc((len1 + len2)*sizeof(double));
    
    for(i = 0; i < len1; i++)
    {
        arr[i] = arr1[i];
    }
    
    for(i = len1; i < (len1 + len2); i++)
    {
        arr[i] = arr2[i - len1];
    }
    
    return arr;
}

void arr_print(double *arr, int len)
{
    int i;
    
    for(i = 0; i < len; i++)
    {        
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}