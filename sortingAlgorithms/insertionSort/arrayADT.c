#include "../../arrayADT/logic.c"

/*
    The below function will take an Array ADT as an input and will sort it using Insertion sort...
*/

void insertionSortArrayADT(Array *a){
    int len = a->length;

    for (int i = 1; i < len; i++)
    {
        int key = a->A[i];
        int j = i - 1;

        while (j >= 0 && a->A[j] > key)
        {
            a->A[j+1] = a->A[j];
            j--;
        }

        a->A[j+1] = key;        
    }
    
    return;
}

/*
    Let's see avove code in action...
*/

int main(){
    Array a;

    init(&a, 10);
    fill(&a);
    
    printf("Before Sorting:\n");
    display(a);

    insertionSortArrayADT(&a);

    printf("After Sorting:\n");
    display(a);

    return 0;
}