#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 300

/*
 * Problem 09. Play with  Int , Double and String
 * 
 * Write a program that, depending on the user’s choice, inputs an int, 
 * double or string variable. If the variable is int or double, the program 
 * increases it by one. If the variable is a string, the program appends "*" at 
 * the end. Print the result at the console. Use switch statement.
 */ 
int main() 
{
    int type;
    int iNumber;
    double dNumber;
    char buffer[BUFFER_LENGTH];
    
    printf("1 --> int\n");
    printf("2 --> double\n");
    printf("3 --> string\n");
    printf("Please choose a type: ");
    scanf("%i", &type);
    
    switch(type)
    {
        case 1:
            printf("\nPlease enter an int: ");
            scanf("%i", &iNumber);
            printf("%i", ++iNumber);            
            break;
        case 2:
            printf("\nPlease enter a double: ");
            scanf("%lf", &dNumber);
            printf("%.3lf", ++dNumber);
            break;
        case 3:
            printf("\nPlease enter a string: ");
            
            // flush stdin because of unread newline or other unexpected 
            // input after calling scanf 
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            
            if(NULL != fgets(buffer, BUFFER_LENGTH, stdin))
            {
                int length = strlen(buffer);
                if(buffer[length - 1] == '\n')
                {
                    buffer[length - 1] = '\0';
                }
                
                printf("%s", buffer);
                printf("*\n");
            }
            break;
        default:
            printf("Wrong type!\n");
            return (EXIT_FAILURE);
    }   

    return (EXIT_SUCCESS);
}

