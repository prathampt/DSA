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

    return 0;
}