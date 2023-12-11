/*
Question: Write a C program to delete all duplicate elements from an array, retaining the first occurrence.
Note: Array elements cannot be deleted. Shift and replace can be done.
*/

#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int *arr, int *size) {
    int newSize = 1;

    for (int i = 1; i < *size; ++i) {
        int isDuplicate = 0;

        for (int j = 0; j < newSize; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            arr[newSize++] = arr[i];
        }
    }

    *size = newSize;
}

int main() {
    int size;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    // Input array elements
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    removeDuplicates(arr, &size);

    // Display the array after removing duplicates
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
