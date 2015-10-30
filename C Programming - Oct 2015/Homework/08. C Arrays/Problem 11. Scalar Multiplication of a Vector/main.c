#include <stdio.h>
#include <stdlib.h>

/*
 * Problem_11._Scalar_Multiplication_of_a_Vector
 * 
 * A Scalar Multiplication of vectors is when you have a given vector 
 * (ex. [a1, a2, ..., an] ) and you want to multiply it by a scalar 
 * (a simple number). The multiplication is done by multiplying the scalar with 
 * each of the vector members. Write a program to perform a scalar 
 * multiplication of a vector. You are given an input number representing the 
 * dimension of a vector on the first input line. On the second input line, 
 * you are given the scalar to multiply the vector and on the next n lines, 
 * you are given the members of the vector.
 */
int main() 
{
    int i;
    int n;
    int scalar;
    
    printf("Length of vector = ");
    scanf("%d", &n);
    printf("scalar = ");
    scanf("%d", &scalar);
    
    int *vector = malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
        vector[i] *= scalar;
    }
    
    /* Print result */
    
    printf("\n Output\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    /* Free allocated memory */
    
    free(vector);

    return (EXIT_SUCCESS);
}

