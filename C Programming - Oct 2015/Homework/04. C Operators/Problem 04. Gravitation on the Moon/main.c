#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 04. Gravitation on the Moon
 * 
 * The gravitational field of the Moon is approximately 17% of that on the 
 * Earth. Write a program that calculates the weight of a man on the moon by a 
 * given weight on the Earth. 
 */
int main() 
{
    double weight;
    
    printf("Input weight = ");
    scanf("%lf", &weight);
    
    double weightOnTheMoon = (weight*17)/100;
    
    printf("\n|   weight  | weight on the Moon |\n");
    printf("| %6lf |       %lf    |\n", weight, weightOnTheMoon);

    return (EXIT_SUCCESS);
}

