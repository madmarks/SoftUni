#include <stdio.h>
#include <inttypes.h>

/*
 * Write a C program using nano or vim that is calculating numbers of 
 * Fibonacci and prints the maximum possible number that can be calculated. 
 * If you answer is larger than 9,3 * 10^18 send me your solution to mail 
 * martinkuvandzhiev@gmail.com . Include the source code or a screenshot of it.
 * 
 */
int main() 
{
    uint64_t Fn_minus_2 = 0;
    uint64_t Fn_minus_1 = 1;
    uint64_t Fn = 1;
    
    while(Fn >= Fn_minus_1)
    {        
        Fn_minus_2 = Fn_minus_1;
        Fn_minus_1 = Fn;
        Fn = Fn_minus_1 + Fn_minus_2;       
    } 
    
    printf("Max uint64_t Fibonacci number = %"PRIu64"\n", Fn_minus_1);

    return 0;
}

