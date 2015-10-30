#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 06. Rectangles
 * 
 * Write an expression that calculates rectangle’s perimeter and area by given 
 * width and height.
 */
int main() 
{
    double width;
    double height;
    
    do
    {
        printf("Input width = ");
        scanf("%lf", &width);
        
        if(width > 0.0)
        {
            printf("Input height = ");
            scanf("%lf", &height);
        }
    }while(width < 0.0 || height < 0.0);
    
    double perimeter = 2 * width + 2 * height;
    double area = width * height;
    
    printf("\n|   width  |   height  | perimeter |     area    |\n");
    printf("| %6lf | %6lf |  %lf |  %lf  |\n", width, height, perimeter, area);

    return (EXIT_SUCCESS);
}

