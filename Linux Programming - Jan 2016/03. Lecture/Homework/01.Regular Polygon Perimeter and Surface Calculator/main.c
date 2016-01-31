#include <stdio.h>
#include <inttypes.h>

#include "perimeter.h"
#include "surface.h"

/*
 * Write a C program that:
 *    - Calculates perimeter and surface of given equilateral figure by 
 *      given side and number of angles
 *    - Program must have files main.c surface.c and perimeter.c
 *    - Compile and run
 *    - Pack to archive
 *    - Pack to .deb
 *    - Prepare manual Makefile
 */
int main(int argc, char** argv) {

    uint32_t n;
    double side;

    printf("Polygon perimeter and surface calculator:\n\n");
    printf("Number of angels n = ");
    scanf("%u", &n);

    printf("Length of side = ");
    scanf("%lf", &side);

    printf("\nperimeter = %.3lf\n", perimeter(n, side));
    printf("surface = %lf\n\n", regular_polygon_surface(n, side));

    return 0;
}

