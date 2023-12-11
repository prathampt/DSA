/*
Question: Write C program to shift all elements of an array by n locations to right or left in
circular fashion. Take all inputs from user.
*/

#include <stdio.h>

void circularShiftRight(int arr[], int size, int n) {
    int temp;

    n = n % size;

    for (int i = 0; i < n; ++i) {
        temp = arr[size - 1];
        for (int j = size - 1; j > 0; --j) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

int main() {
    int size, n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Input shift count
    printf("Enter the number of locations to shift (positive for right, negative for left): ");
    scanf("%d", &n);

    // Perform circular shift
    circularShiftRight(arr, size, n);

    // Display the shifted array
    printf("Array after circular shift:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
