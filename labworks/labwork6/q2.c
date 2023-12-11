/*
Question: Display array elements in reverse order (from last to first) using a macro for array size.
*/

#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE];

    // Input elements of the array
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }

    // Display array elements in reverse order
    printf("Array elements in reverse order:\n");
    for (int i = SIZE - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
