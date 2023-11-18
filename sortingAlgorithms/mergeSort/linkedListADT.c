#include "../../linkedListADT/logic.c"

/*
    The below function will take a Linked List ADT as an input and will sort it using Merge Sort...
*/

Node * merge(Node *left, Node *right){
    if (!left){
        return right;
    }
    else if (!right){
        return left;
    }

    Node *result;

    if (left->data <= right->data){
        result = left;
        result->next = merge(left->next, right);
    }
    else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;    
}

void mergeSortLinkedList(List *l){
    Node *current = *l;
    Node *left, *right;

    if (!current || !current->next) return;

    Node *half = current;
    Node *full = current->next;

    while (full && full->next)
    {
        full = full->next->next;
        half = half->next;
    }

    left = current;
    right = half->next;
    half->next = NULL;

    mergeSortLinkedList(&left);
    mergeSortLinkedList(&right);

    *l = merge(left, right);    

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