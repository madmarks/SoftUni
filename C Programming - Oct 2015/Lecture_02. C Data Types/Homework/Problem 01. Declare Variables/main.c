#include <stdio.h>
#include <stdlib.h>

/*
 * Declare five variables choosing for each of them the most appropriate of the 
 * types char, short, unsigned short, int, unsigned int, long, unsigned long to 
 * represent the following values: 52130, 8942492113, -115, 4825932, 97, -10000, 
 * -35982859328592389. 
 * Choose a large enough type for each number to ensure it will fit in it. 
 */
int main() 
{
    unsigned short a = 52130;
    unsigned long long b = 8942492113;
    short c = -115;
    int d = 4825932;
    unsigned char e = 97;
    short f = -10000;
    long long g = -35982859328592389;
    
    printf("52130 = %d\n", a);
    printf("8942492113 = %llu\n", b);
    printf("-115 = %d\n", c);
    printf("4825932 = %d\n", d);
    printf("97 = %d\n", e);
    printf("-10000 = %d\n", f);
    printf("-35982859328592389 = %lld\n", g);
    
    return (EXIT_SUCCESS);
}

