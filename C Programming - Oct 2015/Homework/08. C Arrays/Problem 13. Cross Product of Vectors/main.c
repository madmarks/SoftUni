#include <stdio.h>
#include <stdlib.h>

/*
 * Problem_13._Cross_Product_of_Vectors
 * 
 * The cross product of vectors is defined only in a dimension where n = 3. 
 * It takes as input two vectors and produces a new one in the same dimension. 
 * Each member of the resulting vector is a result of the determinant of 
 * the members from different rows in the first vector. Example:
 * 
 * [a1, a2, a3] x [b1, b2, b3] = [(a2*b3–a3*b2), (a3*b1–a1*b3), (a1*b2–a2*b1)]
 * 
 * Note how the middle row is calculated with the terms backwards or you could
 * just take the negative of the regular calculation. On the first 3 input lines,
 * you are given the members of the first vectors, and on the next ones, you are
 * given the members of the second one.
 */
int main() 
{
    int i;
    int dimensions = 3;
    
    int a[dimensions];
    int b[dimensions];
    int res[dimensions];

    for(i = 0; i < dimensions; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < dimensions; i++)
    {
        scanf("%d", &b[i]);
    }
    
    res[0] = (a[1] * b[2]) - (a[2] * b[1]); 
    res[1] = (a[2] * b[0]) - (a[0] * b[2]);
    res[2] = (a[0] * b[1]) - (a[1] * b[0]);
    
    /* Print result */
    
    printf("\n Output\n");
    printf("[%d, %d, %d]\n", res[0], res[1], res[2]);

    return (EXIT_SUCCESS);
}

