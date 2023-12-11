/*
Question: Reverse elements of an array without using an additional array.
*/

#include <stdio.h>

void reverseArray(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        // Swap elements at positions i and j
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
}

int main() {
    int size;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    reverseArray(arr, size);

    // Display the reversed array
    printf("Reversed array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
