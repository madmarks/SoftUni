#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * Write a program that safely compares floating-point numbers (double) with 
 * precision eps=0.000001. Note that we cannot directly compare two 
 * floating-point numbers a and b by a==b because of the nature of the 
 * floating-point arithmetic. Therefore, we assume two numbers are equal if they
 * are more closely to each other than a fixed constant eps. 
 */
int main() 
{
    double a;
    double b;
    double eps = 0.000001;
    char *explanation;
    
    printf("Input a: ");
    scanf("%20lf", &a);
    printf("Input b: ");
    scanf("%20lf", &b);
    
    double diff = fabs(a - b);
    
    if(diff < eps)
    {
        explanation = "The difference %.8lf < eps\n";
    }
    else if(diff > (eps + 0.01*eps))
    {
        explanation = "The difference of %.8lf is too big (> eps)\n";
    }
    else
    {
        explanation = "Border case. The difference %.8lf == eps. We consider the numbers are different.\n";
    }
   
    printf("|  Number a  |  Number b  | Equal (with precision eps=%.6lf) | Explanation\n", eps);
    
    char str[160];
    strcpy(str, "| %-10.8lf | %-10.8lf | %-35s | ");
    strcat(str, explanation);
    
    printf(str, a, b, (diff < eps) ? "true" : "false", diff);
    
    return (EXIT_SUCCESS);
}

