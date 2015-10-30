#include <stdio.h>
#include <stdlib.h>

#include "arr_func.h"

/*
 * Problem 5. Array Manipulation
 * 
 * Declare the following functions in a header file(.h). Implement them in a 
 * separate .c file. Include the .h file in your main program and demonstrate 
 * the written functions.
 * 
 *   * arr_min()-returns the smallest element in the array
 *   * arr_max()-returns the largest element in the array
 *   * arr_clear()-sets all array elements to 0
 *   * arr_average()-returns the average of all elements 
 *   * arr_sum()-returns the sum of all array elements
 *   * arr_contains()-returns whether the array contains the specified element
 *
 * Bonus:
 *   * arr_merge()-receives two arrays, merges them into one and returns a 
 *                 pointer to the resulting array
 */
int main() 
{
    int i;
    double arr_1[] = {3.5, 2, 7.8, 0.01, 11, 0, -2.7, 15, 4.78, -7, 0.01};
    
    int len_1 = sizeof(arr_1) / sizeof(double);
    
    arr_print(arr_1, len_1);
    
    printf("\nThe smallest element in the array: %.2f\n", arr_min(arr_1, len_1));    
    printf("\nThe largest element in the array: %.2f\n", arr_max(arr_1, len_1));
    printf("\nThe average of all elements: %.4f\n", arr_average(arr_1, len_1));
    printf("\nThe sum of all array elements: %.2f\n", arr_sum(arr_1, len_1));
    
    double number = -7;
    printf("\nThe array contains \'%.2f\': %s\n", number,
            arr_contains(arr_1, len_1, number) ? "true" : "false");
    
    double arr_2[] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    int len_2 = sizeof(arr_2) / sizeof(double);
    
    double *merged_array = arr_merge(arr_1, len_1, arr_2, len_2);
    printf("\nNew arr after merge of arr_1 and arr_2:\n");
    arr_print(merged_array, (len_1 + len_2));
    
    arr_clear(arr_1, len_1);
    printf("\narr_1 after arr_clear():\n");
    arr_print(arr_1, len_1);

    return (EXIT_SUCCESS);
}

