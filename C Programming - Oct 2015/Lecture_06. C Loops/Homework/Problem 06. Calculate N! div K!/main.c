#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 6. Calculate N!/K!
 * 
 * Write a program that calculates n!/k! for given n and k (1 < k < n < 100).
 * Use only one loop. 
 */
int main() 
{
    int n;
    int k;
    unsigned long long factorialN = 1;
    unsigned long long factorialK = 1;
    
    printf("Input n = ");
    scanf("%d", &n);
    printf("Input k = ");
    scanf("%d", &k);
    
    int i;
    for(i = 1; i <= n; i++)
    {
        factorialN *= i;
        
        if(i <= k)
        {
            factorialK *= i;
        }
    }
    
    printf("\n|  n  |  k  |   n!/k!  |\n");
    printf("| %3d | %3d | %8llu |\n", n, k, factorialN/factorialK);
    
    return (EXIT_SUCCESS);
}

