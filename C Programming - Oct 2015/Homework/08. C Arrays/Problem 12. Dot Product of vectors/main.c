#include <stdio.h>
#include <stdlib.h>

/*
 * Problem_12._Dot_Product_of_vectors
 * 
 * A Dot product of two vectors is a scalar which is a result of the sum of 
 * the product of each of the two vectors’ members. For example, if we have 
 * the vector [a1, a2, ..., an] and the vector [b1, b2, ..., bn], their dot 
 * product is: (a1b1 + a2b2 + ... + anbn). You are given the length n of each of 
 * the vectors on the first input line (In order to perform a dot product of 
 * two vectors, they have to be with equal dimensions). On the next n lines, 
 * you are given the members of the first vector, and on the next n ones, 
 * the members of the second one.
 */
int main() 
{
    int i;
    int n;
    long long dotProductOfTwoVectors = 0;
    
    printf("Length of vectors = ");
    scanf("%d", &n);
    
    int *vector1 = malloc(n * sizeof(int));
    int *vector2 = malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        scanf("%d", &vector1[i]);
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d", &vector2[i]);
        
        dotProductOfTwoVectors += vector1[i] * vector2[i];
    }
    
    /* Print result */
    
    printf("\n Output\n");
    printf("%lld\n", dotProductOfTwoVectors);
       
    /* Free allocated memory */
    
    free(vector1);
    free(vector2);
    
    return (EXIT_SUCCESS);
}

