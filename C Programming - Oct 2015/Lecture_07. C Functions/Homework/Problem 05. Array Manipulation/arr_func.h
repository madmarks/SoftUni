#ifndef ARR_FUNC_H
#define	ARR_FUNC_H

double arr_min(double *arr, int len);
double arr_max(double *arr, int len);
void arr_clear(double *arr, int len);
double arr_average(double *arr, int len);
double arr_sum(double *arr, int len);
_Bool arr_contains(double *arr, int len, double element);
double *arr_merge(double *arr1, int len1, double *arr2, int len2);

void arr_print(double *arr, int len);

#endif	/* ARR_FUNC_H */

