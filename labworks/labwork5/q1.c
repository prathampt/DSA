/*
Question: Write a program that calculates the sum of squares of the elements of an integer array of size 10.
*/

#include <stdio.h>
#define size 10

int main() {
    int arr[size];
    int sumOfSquares = 0;

    // Input elements of the array
    printf("Enter 10 integers:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of squares
    for (int i = 0; i < size; ++i) {
        sumOfSquares += arr[i] * arr[i];
    }

    // Print the result
    printf("Sum of squares: %d\n", sumOfSquares);

    return 0;
}
