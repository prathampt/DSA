#include <stdio.h>
#include "logic.c"

int main() {
    Array arr1, arr2, arr3;
    init(&arr1, 10);
    init(&arr2, 5);

    printf("Adding elements to arr1:\n");
    fill(&arr1);

    printf("\nDisplaying arr1:\n");
    display(arr1);

    printf("\nAdding elements to arr2:\n");
    append(&arr2, 15);
    append(&arr2, 44);
    append(&arr2, 6);
    append(&arr2, 52);

    printf("\nDisplaying arr2:\n");
    display(arr2);

    printf("\nInserting 88 at position 3 in arr2:\n");
    insert(&arr2, 88, 3);
    display(arr2);

    printf("\nRemoving element 5 from arr1:\n");
    int removedElement = removeElement(&arr1, 5);
    printf("Removed Element: %d\n", removedElement);
    display(arr1);

    printf("\nRemoving element at index 2 from arr2:\n");
    int removedIndex = removeAtIndex(&arr2, 2);
    printf("Removed Element at Index 2: %d\n", removedIndex);
    display(arr2);

    printf("\nReversing arr1:\n");
    reverse(&arr1);
    display(arr1);

    printf("\nFinding minimum element in arr2:\n");
    int minimum = min(arr2);
    printf("Minimum Element: %d\n", minimum);

    printf("\nFinding maximum element in arr2:\n");
    int maximum = max(arr2);
    printf("Maximum Element: %d\n", maximum);

    printf("\nSorting arr1:\n");
    sort(&arr1);
    display(arr1);

    printf("\nJoining arr1 and arr2 into arr3:\n");
    arr3 = join(arr1, arr2);
    display(arr3);

    free(arr1.A);
    free(arr2.A);
    free(arr3.A);

    return 0;
}
