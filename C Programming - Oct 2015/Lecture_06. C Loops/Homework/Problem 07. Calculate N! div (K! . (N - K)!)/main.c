#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 7. Calculate N!/(K! * (N-K)!)
 * 
 * In combinatorics, the number of ways to choose k different members out of a 
 * group of n different elements (also known as the number of combinations) is 
 * calculated by the following formula: 
 * 
 *  (n)       n!
 *  ( ) = -----------
 *  (k)    k!(n - k)!
 * 
 * For example, there are 2598960 ways to withdraw 5 cards out of a standard 
 * deck of 52 cards. Your task is to write a program that calculates 
 * n!/(k!* (n-k)!) for given n and k (1 < k < n < 100).
 * Try to use only two loops.
 */
int main() 
{
    int n;
    int k;
    unsigned long long factorialK = 1;
    
    /* 
     * I will reduce calculations using that
     * n!/(n-k)! = n*(n-1)*(n-2)...(n-k+2)*(n-k+1) 
     */
    unsigned long long kPermutationsOfN = 1;
    
    printf("Input n = ");
    scanf("%d", &n);
    printf("Input k = ");
    scanf("%d", &k);
    
    int i;
    for(i = 1; i <= n; i++)
    {
        if(i <= k)
        {
            factorialK *= i;
        }
        
        if(i > n - k)
        {
           kPermutationsOfN *= i; 
        }
    }
    
    printf("\n|  n  |  k  | n!/(k!*(n-k)!) |\n");
    printf("| %3d | %3d | %14llu |\n", n, k, kPermutationsOfN/factorialK);

    return (EXIT_SUCCESS);
}

