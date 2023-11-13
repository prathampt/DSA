#include "../../arrayADT/logic.c"

/*
    The below function will take an Array ADT as an input and will sort it using Bubble sort...
*/

void bubbleSortArrayADT(Array *a){
    int length = a->length, swapped = 0;

    for (int i = 0; i < length; i++)
    {
        swapped = 0;

        for (int j = 0; j < length - i -1; j++)
        {
            if (a->A[j] > a->A[j+1])
            {
                int temp = a->A[j];
                a->A[j] = a->A[j+1];
                a->A[j+1] = temp;
                swapped = 1;
            }
            
        }

        if (!swapped)
        {
            break;
        }
        
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

    bubbleSortArrayADT(&a);

    printf("After Sorting:\n");
    display(a);

    return 0;
}