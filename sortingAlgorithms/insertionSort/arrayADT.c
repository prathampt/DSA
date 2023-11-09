#include "../../arrayADT/logic.c"

/*
    The below function will take an Array ADT as an input and will sort it using Insertion sort...
*/



/*
    Let's see avove code in action...
*/

int main(){
    Array a;

    init(&a, 10);
    fill(&a);
    
    printf("Before Sorting:\n");
    display(a);

    // selectionSortArrayADT(&a);

    printf("After Sorting:\n");
    display(a);

    return 0;
}