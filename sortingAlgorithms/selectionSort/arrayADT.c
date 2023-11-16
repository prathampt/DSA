#include "../../arrayADT/logic.c"

/*
    The below function will take an Array ADT as an input and will sort it using Selection sort...
*/

void selectionSortArrayADT(Array *a){
    int length = a->length;

    for (int i = 0; i < length; i++)
    {   
        int smallestIndex = i;

        for (int j = i+1; j < length; j++)
        {
            if (a->A[smallestIndex] > a->A[j])
            {
                smallestIndex = j;
            }
        
        }

        int temp = a->A[smallestIndex];
        a->A[smallestIndex] = a->A[i];
        a->A[i] = temp;
        
    }
    
    return;
}

/*
    Let's see above code in action...
*/

int main(){
    Array a;

    init(&a, 10);
    fill(&a);
    
    printf("Before Sorting:\n");
    display(a);

    selectionSortArrayADT(&a);

    printf("After Sorting:\n");
    display(a);

    return 0;
}