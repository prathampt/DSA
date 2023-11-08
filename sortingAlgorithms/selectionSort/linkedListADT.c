#include "../../linkedListADT/logic.c"

/*
    The below function will take a Linked List ADT as an input and will sort it using Selection Sort...
*/

void selectionSortLinkedList(List * l){
    if (!(*l)) return;  

    Node *p = *l;
    Node *q = NULL, *s = NULL;

    while (p->next)
    {
        s = p;
        q = p->next;
        while (q)
        {
            if (s->data > q->data)
            {
                s = q;
            }
            q = q->next;            
        }
        swapNodes(l, p, s);
        p = s; // This is very important step...
        p = p->next;        
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

    selectionSortLinkedList(&l);

    printf("After Sorting:\n");
    display(l);

    return 0;
}