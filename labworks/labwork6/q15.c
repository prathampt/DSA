/*
Question: Write code to find the second-largest element in a 1D array.
*/

#include <stdio.h>

void findSecondLargest(int arr[], int size) {
    if (size < 2) {
        printf("Array size should be at least 2 to find the second-largest element.\n");
        return;
    }

    int firstLargest, secondLargest;

    // Initialize firstLargest and secondLargest with the first two elements
    if (arr[0] > arr[1]) {
        firstLargest = arr[0];
        secondLargest = arr[1];
    } else {
        firstLargest = arr[1];
        secondLargest = arr[0];
    }

    // Iterate through the array to find the second-largest element
    for (int i = 2; i < size; ++i) {
        if (arr[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            secondLargest = arr[i];
        }
    }

    printf("The second-largest element in the array is: %d\n", secondLargest);
}

int main() {
    const int size = 10;
    int array[size];

    // Input array elements
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    // Find the second-largest element in the array
    findSecondLargest(array, size);

    return 0;
}
