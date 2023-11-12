#include "logic.c"

int main(){
    List l;
    init(&l);

    append(&l, 20);
    display(l);
    append(&l, 30);
    display(l);
    insertAtBeginning(&l, 10);
    display(l);
    fill(&l, 3);
    display(l);
    insertAtIndex(&l, 40, 3);
    display(l);

    printf("Length of DLL is: %d\n", length(l));

    fill(&l, 5);
    display(l);

    printf("Removed element: %d\n", removeEnd(&l));    
    display(l);
    printf("Removed element: %d\n", removeBeginning(&l));
    display(l);
    printf("Removed element: %d\n", removeAtIndex(&l, 4));
    display(l);
    printf("Removed element: %d\n", removeNode(&l, l.rear->previous->previous));
    display(l);

    swapNodes(&l, l.front, l.front->next->next->next);
    display(l);
    swapNodes(&l, l.front->next->next, l.front->next->next->next);
    display(l);

    printf("Destroying the list:\n");
    destroy(&l);
    display(l);

    return 0;
}