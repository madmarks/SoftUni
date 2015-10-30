#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 12. Randomize the Numbers 1...N
 * 
 * Write a program that enters an integer n and prints the numbers 
 * 1, 2, ..., n in random order. 
 */
int main() {
    int i;
    int n;
    int index;
    int tempElement;

    printf("Input n = ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof (int));

    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        srand(time(NULL) + i);
        index = rand() % n;

        // swap 2 array elements
        tempElement = arr[i];
        arr[i] = arr[index];
        arr[index] = tempElement;
    }

    printf("\n|  n  |  randomized numbers 1...n\n");
    printf("| %3d | ", n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return (EXIT_SUCCESS);
}

