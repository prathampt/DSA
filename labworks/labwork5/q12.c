/*
Question: C program to find the nearest lesser and greater element in an array.
*/

#include <stdio.h>
#include <limits.h>

void findNearestElements(int arr[], int size, int key, int *lesser, int *greater) {
    *lesser = INT_MIN;
    *greater = INT_MAX;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < key && arr[i] > *lesser) {
            *lesser = arr[i];
        }
        if (arr[i] > key && arr[i] < *greater) {
            *greater = arr[i];
        }
    }
}

int main() {
    int size, key, lesser, greater;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Input key element
    printf("Enter the key element: ");
    scanf("%d", &key);

    // Find nearest lesser and greater elements
    findNearestElements(arr, size, key, &lesser, &greater);

    // Display the results
    printf("Nearest lesser element: %d\n", (lesser != INT_MIN) ? lesser : -1);
    printf("Nearest greater element: %d\n", (greater != INT_MAX) ? greater : -1);

    return 0;
}
