#include <stdio.h>
#include <inttypes.h>

uint64_t fact(uint64_t);

int main()
{
    uint64_t n;
    
    printf("n = ");
    scanf("%"PRIu64, &n);

    printf("%"PRIu64"! = %"PRIu64"\n", n, fact(n));

    return 0;
}


uint64_t fact(uint64_t n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
