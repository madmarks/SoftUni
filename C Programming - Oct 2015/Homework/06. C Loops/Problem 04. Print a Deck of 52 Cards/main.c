#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 4. Print a Deck of 52 Cards
 * 
 * Write a program that generates and prints all possible cards from a standard 
 * deck of 52 cards (without the jokers). The cards should be printed using 
 * the classical notation (like 5S (¦), AH (¦), 9C (¦)and KD (¦)). The card 
 * faces should start from 2 to A. Print each card face in its four possible 
 * suits: clubs, diamonds, hearts and spades. Use 2 nested for-loops and a 
 * switch-case statement.
 */
int main() {
    int i;
    int j;

    for (i = 2; i < 15; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            switch (i) 
            {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    printf("%d", i);
                    break;
                case 11:
                    printf("J");
                    break;
                case 12:
                    printf("D");
                    break;
                case 13:
                    printf("K");
                    break;
                case 14:
                    printf("A");
                    break;
            }

            switch (j) 
            {
                case 0:
                    printf("C ");
                    break;
                case 1:
                    printf("D ");
                    break;
                case 2:
                    printf("H ");
                    break;
                case 3:
                    printf("S ");
                    break;
            }
        }

        printf("\n");
    }

    return (EXIT_SUCCESS);
}

