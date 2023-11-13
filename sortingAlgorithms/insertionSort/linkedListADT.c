#include "../../linkedListADT/logic.c"

/*
    The below function will take a Linked List ADT as an input and will sort it using Insertion Sort...
*/

void insertionSortLinkedList(List *l){
    if (!*l) return;

    int index = 0;

    Node *p = *l;
    Node *q = p->next;

    while (q)
    {   
        p = *l;
        index = 0;

        while (p->data < q->data && p != q)
        {
            p = p->next;
            index++;
        }

        if (p == q){
            q = q->next;
            continue;
        } 

        Node * r = q->next;

        removeAndInsert(l, q, index);

        q = r;        
    }

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

    insertionSortLinkedList(&l);

    printf("After Sorting:\n");
    display(l);

    return 0;
}