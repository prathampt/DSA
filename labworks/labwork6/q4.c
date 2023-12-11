/*
Question: Display elements of an array in a triangle pattern using formatting for uniform display. Take array input from the user.
*/

#include <stdio.h>

#define SIZE 5

int main() {
    int A[SIZE];

    // Input elements of the array
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &A[i]);
    }

    // Display elements in a triangle pattern
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%-4d", A[j]);  // Using formatting for uniform display
        }
        printf("\n");
    }

    return 0;
}
