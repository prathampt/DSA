/*
Question: Write a program to search for an element accepted from the user in an array of floating-point values of size 50.
Display the index if the element is found, else display the message "Not Found."
*/

#include <stdio.h>

#define SIZE 50

int main() {
    float arr[SIZE];
    float searchElement;

    // Input elements of the array
    printf("Enter %d floating-point values:\n", SIZE);
    for (int i = 0; i < SIZE; ++i) {
        scanf("%f", &arr[i]);
    }

    // Input element to search
    printf("Enter the element to search: ");
    scanf("%f", &searchElement);

    // Search for the element in the array
    int index = -1;  // Default value if the element is not found
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == searchElement) {
            index = i;
            break;  // Element found, exit the loop
        }
    }

    // Display the result
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }

    return 0;
}
