#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <inttypes.h>

_Bool is_prime(uint64_t);
_Bool is_prime_slow(uint64_t);

/*
 * Write a C program that find largest prime number for a period of time:
 *    - For example, you start the program, write the number 1.8 and the program 
 *      starts finding prime numbers. When 1.8 seconds has passed the program 
 *      returns the largest found prime number for this period.
 *    - Compile and run
 *    - Pack to arhive
 *    - Pack to .deb
 *    - Prepare manual Makefile
 */
int main(int argc, char** argv) {

    double period;
    double duration = 0.0;
    time_t t;
    uint64_t prime;

    printf("Input period of time (in seconds)\n");
    printf("period = ");
    scanf("%lf", &period);

    t = clock();

    uint64_t i;
    uint64_t n = (uint64_t) 2;
    do {
        n++;
        
        if (n == (uint64_t) 3) {
            prime = n;
            continue;
        }

        if (n % 2 == 0 || n % 3 == 0) 
            continue;

        for (i = 5; i * i <= n; i += 6) {
            
            if (n % i == (uint64_t) 0 || n % (i + 2) == (uint64_t) 0)
                break;            
        }

        if(i * i > n)
            prime = n;

    } while ((duration = (double) ((double) (clock() - t) / CLOCKS_PER_SEC)) < period);

    printf("Largest prime number found for %.3lf sec is %"PRIu64"\n",
            period, prime);

    return 0;
}

_Bool is_prime(uint64_t n) {
    if (n <= 3) {
        return n > (uint64_t) 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    /*
     * To test a prime, you should go all the way from i=2 to i<=ceil(sqrt(n)). 
     * You missed 2 numbers in your test: First, cast to (int) makes sqrt(n) 
     * trunk the decimals. Second, you used i<sq, when it should be i<=sq
     * Now, suppose a number that fits this problem. A composite number n that 
     * has ceil(sqrt(n)) as the smaller factor. Your inner loop runs for i like: 
     * (5, 7), (11, 13), (17, 19), (23, 25), (29, 31), (35, 37), (41, 43), and 
     * so on, n%i and n%(i+2). 
     * Suppose we get sqrt(1763)=41.98. Being 1763=41*43 a composite number. 
     * 
     * use i*i<=n in for loop instead of i<=ceil(sqrt(n))
     */
    for (uint64_t i = 5; i * i <= n; i += 6) {

        if (n % i == (uint64_t) 0 || n % (i + 2) == (uint64_t) 0) {
            return false;
        }
    }

    return true;
}

_Bool is_prime_slow(uint64_t n) {

    if (n <= (uint64_t) 3)
        return n > (uint64_t) 1;

    for (uint64_t i = 2; i * i <= n; i++) {
        if (n % i == (uint64_t) 0)
            return false;
    }

    return true;
}