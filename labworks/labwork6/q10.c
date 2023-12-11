/*
Question: Write a program to check if elements of an array are the same when read from front or back. (Palindrome)
Example: 2 3 15 15 3 2
*/

#include <stdio.h>

int isPalindrome(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        if (arr[i] != arr[j]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Palindrome
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

    // Check if the array is a palindrome
    if (isPalindrome(arr, size)) {
        printf("The elements of the array are the same when read from front or back (Palindrome).\n");
    } else {
        printf("The elements of the array are not the same when read from front or back (Not a palindrome).\n");
    }

    return 0;
}
