#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define RESULT_LENGTH 100

char *getNumberAsWord(int n)
{
    char *result = malloc(10);
    result[0] = '\0';
    
    switch(n)
    {
        case 0:
            strcat(result, "zero");
            return result;
        case 1:
            strcat(result, "one");
            return result;
        case 2:
            strcat(result, "two");
            return result;
        case 3:
            strcat(result, "three");
            return result;
        case 4:
            strcat(result, "four");
            return result;
        case 5:
            strcat(result, "five");
            return result;
        case 6:
            strcat(result, "six");
            return result;
        case 7:
            strcat(result, "seven");
            return result;
        case 8:
            strcat(result, "eight");
            return result;
        case 9:
            strcat(result, "nine");
            return result;            
        case 10:
            strcat(result, "ten");
            return result;
        case 11:
            strcat(result, "eleven");
            return result;
        case 12:
            strcat(result, "twelve");
            return result;
        case 13:
            strcat(result, "thirteen");
            return result;
        case 14:
            strcat(result, "fourteen");
            return result;
        case 15:
            strcat(result, "fifteen");
            return result;
        case 16:
            strcat(result, "sixteen");
            return result;
        case 17:
            strcat(result, "seventeen");
            return result;
        case 18:
            strcat(result, "eighteen");
            return result;
        case 19:
            strcat(result, "nineteen");
            return result;
        case 20:
            strcat(result, "twenty");
            return result;
        case 30:
            strcat(result, "thirty");
            return result;
        case 40:
            strcat(result, "forty");
            return result;
        case 50:
            strcat(result, "fifty");
            return result;
        case 60:
            strcat(result, "sixty");
            return result;
        case 70:
            strcat(result, "seventy");
            return result;
        case 80:
            strcat(result, "eighty");
            return result;
        case 90:
            strcat(result, "ninety");
            return result;            
    }
    
    // result must be freed in caller function -> free(result);
}

/*
 * Problem 11. Number as Words
 * 
 * Write a program that converts a number in the range [0...999] to words, 
 * corresponding to the English pronunciation. 
 */
int main() 
{
    int number;
    int d[3];
    char result[RESULT_LENGTH];
    char *word;
    _Bool hasHundreds = false;
    
    printf("Input number = ");
    scanf("%i", &number);
    
    if(number < 0 || 999 < number)
    {
        printf("Wrong input!");
        return (EXIT_FAILURE);
    }
    
    d[0] = number % 10;
    d[1] = (number / 10) % 10;
    d[2] = (number / 100) % 10;
    
    int lastTwoDigitsNumber = d[1]*10 + d[0];
    
    result[0] = '\0';
    
    if(d[2] > 0)
    {
        hasHundreds = true;
        
        word = getNumberAsWord(d[2]);
        strcat(result, word);
        free(word);
        strcat(result, " hundred");      
        
        if(lastTwoDigitsNumber > 0)
        {
            strcat(result, " and ");           
        }
    }
    
    if(lastTwoDigitsNumber == 0)
    {
        if(!hasHundreds)
        {
            strcat(result, "zero");
        }
    }
    else if(lastTwoDigitsNumber <= 19)
    {
        word = getNumberAsWord(lastTwoDigitsNumber);
        strcat(result, word);
        free(word);
    }
    else
    {
        word = getNumberAsWord(d[1]*10);
        strcat(result, word);
        free(word);

        if(d[0] > 0)
        {                    
            strcat(result, " ");
            word = getNumberAsWord(d[0]);
            strcat(result, word);
            free(word);
        }
    }
    
    result[0] -= 32; // First letter to Upper case
    
    printf("\n| number | number as words \n");
    printf("|   %3i  | %-s \n", number, result);

    return (EXIT_SUCCESS);
}

