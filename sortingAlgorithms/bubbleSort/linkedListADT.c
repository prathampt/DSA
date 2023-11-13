#include "../../linkedListADT/logic.c"

/*
    The below function will take a Linked List ADT as an input and will sort it using Bubble Sort...
*/

void bubbleSortLinkedList(List * l){
    if (!(*l)) return; 

    int len = length(*l);

    int swapped = 0; 

    Node *p = NULL, *q = NULL, *s = NULL;

    for (int i = 0; i < len; i++)
    {
        p = *l;
        q = p->next;

        while (q != s)
        {
            if (p->data > q->data)
            {
                swapNodes(l, p, q);
            }
            
            p = q;
            q = q->next;
        }

        s = p;
        
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

    bubbleSortLinkedList(&l);

    printf("After Sorting:\n");
    display(l);

    return 0;
}