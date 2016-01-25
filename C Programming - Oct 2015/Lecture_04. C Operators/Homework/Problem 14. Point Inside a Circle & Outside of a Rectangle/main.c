#include <stdio.h>
#include <stdlib.h>

#define CIRCLE_CENTER_X 1
#define CIRCLE_CENTER_Y 1
#define CIRCLE_RADIUS 1.5

#define RECTANGLE_TOP_LEFT_CORNER_X -1
#define RECTANGLE_TOP_LEFT_CORNER_Y 1
#define RECTANGLE_WIDTH 6
#define RECTANGLE_HEIGHT 2

/*
 * Problem 14. Point Inside a Circle & Outside of a Rectangle
 * 
 * Write an expression that checks for given point (x, y) if it is 
 * within the circle K({1,1}, 1.5) and out of the 
 * rectangle R(top=1, left=-1, width=6, height=2).
 * Print yes or no.
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
    
    _Bool isInsideRectangle = RECTANGLE_TOP_LEFT_CORNER_X <= x 
        && (x <= RECTANGLE_TOP_LEFT_CORNER_X + RECTANGLE_WIDTH) 
        && (RECTANGLE_TOP_LEFT_CORNER_Y - RECTANGLE_HEIGHT <= y) 
        && (y <= RECTANGLE_TOP_LEFT_CORNER_Y);  
    
    printf("\n|   x   |   y   | inside |\n");
    printf("|  %4.2lf |  %4.2lf |   %3s  |\n", x, y, 
            (isInsideCircle && !isInsideRectangle) ? "yes" : "no");

    return (EXIT_SUCCESS);
}