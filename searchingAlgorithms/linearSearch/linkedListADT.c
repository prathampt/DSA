#include "../../linkedListADT/logic.c"
#include <limits.h>

int linearSearch(List l, int data){
    if (!l) return INT_MIN;

    int i = 0;
    while (l){
        if (l->data == data){
            return i;
        }
        i++;
        l = l->next;
    }

    return INT_MIN;    
}

int main(){
    List l;
    init(&l);
    fill(&l, 15);

    display(l);

    printf("The element %d is at index %d\n", 22, linearSearch(l, 22));

    return 0;
}