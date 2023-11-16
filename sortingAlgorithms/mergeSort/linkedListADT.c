#include "../../linkedListADT/logic.c"

/*
    The below function will take a Linked List ADT as an input and will sort it using Merge Sort...
*/

void mergeSortLinkedList(List * l){
    
    return;
}

/*
    Let's see above code in action...
*/

int main(){
    List l;
    init(&l);

    fill(&l, 14);

    printf("Before Sorting:\n");
    display(l);

    mergeSortLinkedList(&l);

    printf("After Sorting:\n");
    display(l);

    return 0;
}