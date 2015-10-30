#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUFFER_LENGTH 200

/*
 * Problem 10. Odd and Even Product
 * 
 * You are given n integers (given in a single line, separated by a space). 
 * Write a program that checks whether the product of the odd elements is 
 * equal to the product of the even elements. Elements are counted from 1 to n, 
 * so the first element is odd, the second is even, etc.
 */
int main() {
    int count = 1;
    char *endPtr;
    int val;

    long long productEven = 1;
    long long productOdd = 1;

    const char *delimiters = " ";
    char buffer[BUFFER_LENGTH];

    printf("Input integers in a single line, separated by a space:\n");
    fgets(buffer, BUFFER_LENGTH, stdin);

    int length = strlen(buffer);
    if (buffer[length - 1] == '\n')
        buffer[length - 1] = '\0';

    char *token;
    if (NULL != (token = strtok(buffer, delimiters))) {
        /* To distinguish success/failure after call */
        errno = 0;

        val = strtol(token, &endPtr, 10);

        /* Check for various possible errors */

        if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
                || (errno != 0 && val == 0)) {
            perror("strtol");
            return (EXIT_FAILURE);
        }

        if (endPtr == buffer) {
            fprintf(stderr, "No digits were found\n");
            return (EXIT_FAILURE);
        }

        productOdd *= val;
        count++;

        while (NULL != (token = strtok(NULL, delimiters))) {
            /* To distinguish success/failure after call */
            errno = 0;

            val = strtol(token, &endPtr, 10);

            /* Check for various possible errors */

            if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
                    || (errno != 0 && val == 0)) {
                perror("strtol");
                return (EXIT_FAILURE);
            }

            if (endPtr == buffer) {
                fprintf(stderr, "No digits were found\n");
                return (EXIT_FAILURE);
            }

            if (count % 2 == 0) {
                productEven *= val;
            } else {
                productOdd *= val;
            }

            count++;
        }
    }

    printf("\n| result \n");
    printf("|-------------\n");
    if (productEven == productOdd) {
        printf("| yes\n");
        printf("| product = %lld\n", productEven);
    } else {
        printf("| no\n");
        printf("| odd_product = %lld\n", productOdd);
        printf("| even_product = %lld\n", productEven);
    }

    return (EXIT_SUCCESS);
}