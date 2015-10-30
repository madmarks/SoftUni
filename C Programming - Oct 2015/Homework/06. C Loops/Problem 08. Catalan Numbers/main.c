#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 8. Catalan Numbers
 * 
 * In combinatorics, the Catalan numbers are calculated by the following formula:
 * 
 *            (2n)!
 *        -------------
 *        (n + 1)! * n!
 * 
 * Write a program to calculate the n-th Catalan number by given n (1 < n < 100).
 */
int main() 
{
    int n;
    int i;
    unsigned long long factorialN = 1;
//    unsigned long long factorialNplus1 = 1;
//    unsigned long long factorial2N = 1;
    
    /* 
     * I will reduce calculations using that
     * (2n)!/(n+1)! = 2n*(2n-1)*(2n-2)...(n+3)*(n+2) 
     */
    unsigned long long numerator = 1;   

    unsigned long long result;
    
    printf("Input n = ");
    scanf("%d", &n);
    
    for(i = 1; i <= 2*n; i++)
    {       
        if(i <= n)
        {
            factorialN *= i;
            
            // when you want to do all calculations
//            factorialNplus1 = (i + 1) * factorialN; 
        }
        
        // when you want to do all calculations
//        factorial2N *= i;
        
        if(i > n + 1)
        {
            numerator *= i;
        }
    }
    
    //result = (factorial2N/factorialNplus1)/factorialN;
    result = numerator/factorialN;
    
    printf("\n|  n  | Catalan(n) |\n");
    printf("| %3d | %10llu |\n", n, result);

    return (EXIT_SUCCESS);
}

