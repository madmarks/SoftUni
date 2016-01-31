#include "surface.h"

double regular_polygon_surface(uint32_t n, double side)
{
    double angle_radians = PI / n;
    
    return (n / 4.0) * side * side * cos(angle_radians) / sin(angle_radians);
}