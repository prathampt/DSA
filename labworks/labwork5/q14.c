/*
Question: Populate an array of size 100 with values generated randomly between 1 to 1000.
Copy all the numbers divisible by 8 or 15 to a new array. Display both arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void populateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000 + 1;
    }
}

void copyDivisibleNumbers(int source[], int sourceSize, int destination[], int *destSize) {
    for (int i = 0; i < sourceSize; ++i) {
        if (source[i] % 8 == 0 || source[i] % 15 == 0) {
            destination[(*destSize)++] = source[i];
        }
    }
}

int main() {
    int array[ARRAY_SIZE];
    int divisibleArray[ARRAY_SIZE];  // Assuming the worst-case scenario where all elements are divisible
    int divisibleSize = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Populate the array with random values
    populateArray(array, ARRAY_SIZE);

    // Copy numbers divisible by 8 or 15 to a new array
    copyDivisibleNumbers(array, ARRAY_SIZE, divisibleArray, &divisibleSize);

    // Display the original array
    printf("Original array:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n");

    // Display the array with numbers divisible by 8 or 15
    printf("Divisible array:\n");
    for (int i = 0; i < divisibleSize; ++i) {
        printf("%d ", divisibleArray[i]);
    }

    return 0;
}
