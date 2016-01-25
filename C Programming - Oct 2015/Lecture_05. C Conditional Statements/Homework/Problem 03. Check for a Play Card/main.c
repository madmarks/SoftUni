#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Problem 03. Check for a Play Card
 * 
 * Classical play cards use the following signs to designate the card face: 
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K and A. Write a program that enters a 
 * string and prints "yes" if it is a valid card sign or "no" otherwise.
 */
int main() 
{
    char cardSign[3];
    _Bool isValidCard;
    
    printf("Input card sign = ");
    scanf("%2s", cardSign);
    
    switch(cardSign[0])
    {
        case '1':
            if(cardSign[1] != '0')
            {
                isValidCard = false;
                break;
            }
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'J':
        case 'Q':
        case 'K':
        case 'A':
            isValidCard = true;
            break;
        default:
            isValidCard = false;
    }
    
    printf("\n| card sign | Valid card sign? |\n");
    printf("|     %2s    |        %3s       |\n", cardSign, isValidCard ? "yes" : "no");

    return (EXIT_SUCCESS);
}

