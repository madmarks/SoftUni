#include <stdio.h>
#include <stdlib.h>

#define CIRCLE_CENTER_X 0
#define CIRCLE_CENTER_Y 0
#define CIRCLE_RADIUS 2

/*
 * Problem 11. Point in a Circle
 * 
 * Write an expression that checks if given point (x, y) is 
 * inside a circle K({0,0},2).
 */
int main() 
{
    double x;
    double y;
    
    printf("Input x = ");
    scanf("%lf", &x);
    printf("Input y = ");
    scanf("%lf", &y);
    
    double xyDistanceFromCircleCenter = 
        (x - CIRCLE_CENTER_X)*(x - CIRCLE_CENTER_X) + 
        (y - CIRCLE_CENTER_Y)*(y - CIRCLE_CENTER_Y);
    
    _Bool isInsideCircle = 
        CIRCLE_RADIUS * CIRCLE_RADIUS >= xyDistanceFromCircleCenter;
    
    printf("\n|   x   |    y   | inside |\n");
    printf("|  %4.1lf |  %4.3lf |   %3s  |\n", x, y, isInsideCircle ? "Yes" : "No");

    return (EXIT_SUCCESS);
}