/*
Question: Create a new array of size 10 having elements of two sorted arrays in sorted order.
*/

#include <stdio.h>

void mergeArrays(int A[], int B[], int C[]) {
    int i = 0, j = 0, k = 0;

    while (i < 5 && j < 5) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    // Copy the remaining elements of A, if any
    while (i < 5) {
        C[k++] = A[i++];
    }

    // Copy the remaining elements of B, if any
    while (j < 5) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[] = {45, 50, 70, 85, 90};
    int B[] = {30, 40, 60, 75, 80};
    int C[10];

    // Merge the arrays A and B into C
    mergeArrays(A, B, C);

    // Display the merged array C
    printf("Merged array C:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", C[i]);
    }

    return 0;
}
