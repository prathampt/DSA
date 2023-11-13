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

    // Test for isPalindrome function...

    List palindromeTest1, palindromeTest2;
    init(&palindromeTest1);
    init(&palindromeTest2);

    append(&palindromeTest1, 1);
    append(&palindromeTest1, 2);
    append(&palindromeTest1, 3);
    append(&palindromeTest1, 2);
    append(&palindromeTest1, 1);

    display(palindromeTest1);
    printf("Palindrom Test is palindrome: %s\n", isPalindrome(palindromeTest1) ? "True" : "False");

    append(&palindromeTest2, 1);
    append(&palindromeTest2, 2);
    append(&palindromeTest2, 3);
    append(&palindromeTest2, 1);
    append(&palindromeTest2, 2);
    append(&palindromeTest2, 1);

    display(palindromeTest2);
    printf("Palindrom Test is palindrome: %s\n", isPalindrome(palindromeTest2) ? "True" : "False");

    // Test for isPalindrome function ended here...

    // Test for removeDuplicates...

    append(&palindromeTest2, 5);
    printf("Before removing Duplicates: \n");
    display(palindromeTest2);

    removeDuplicates(&palindromeTest2);
    printf("After removing duplicates: \n");
    display(palindromeTest2);

    // Test for removeDuplicates complete...

    // Test for remove and insert...

    display(palindromeTest1);
    removeAndInsert(&palindromeTest1, palindromeTest1->next->next->next, 0);
    display(palindromeTest1);

    // Destroy function...

    destroy(&myList);
    destroy(&testList);
    destroy(&palindromeTest1);
    destroy(&palindromeTest2);

    display(myList);
    return 0;
}