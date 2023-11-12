#include <stdio.h>
#include <stdlib.h>
#include "logic.c"

int main() {
    List myList;
    init(&myList);

    printf("Appending elements to the linked list:\n");
    append(&myList, 10);
    append(&myList, 20);
    append(&myList, 30);
    display(myList);

    printf("\nInserting 5 at the beginning of the linked list:\n");
    insertAtBeginning(&myList, 5);
    display(myList);

    printf("\nRemoving element from the end of the linked list:\n");
    int removedEnd = removeEnd(&myList);
    printf("Removed Element from End: %d\n", removedEnd);
    display(myList);

    printf("\nRemoving element from the beginning of the linked list:\n");
    int removedBeginning = removeBeginning(&myList);
    printf("Removed Element from Beginning: %d\n", removedBeginning);
    display(myList);

    printf("Inserting at index 2:\n");
    addNodeAtPosition(&myList, 24, 2);
    display(myList);
    append(&myList, 10);
    append(&myList, 20);
    append(&myList, 30);
    display(myList);
    addNodeAtPosition(&myList, 35, 3);
    display(myList);

    printf("After swapping: \n");
    swapNodes(&myList, myList->next, myList->next->next->next->next);
    display(myList);

    // Testing the working of reverseEven function...

    List testList;
    init(&testList);

    append(&testList, 1);
    append(&testList, 2);
    append(&testList, 8);
    append(&testList, 9);
    append(&testList, 12);
    append(&testList, 16);
    append(&testList, 18);
    append(&testList, 11);
    append(&testList, 14);   
    append(&testList, 13);

    printf("Before ReverseEven: \n");
    display(testList);

    reverseEven(&testList);

    printf("After ReverseEven: \n");
    display(testList);

    // Test reverseEven function complete...

    return 0;
}