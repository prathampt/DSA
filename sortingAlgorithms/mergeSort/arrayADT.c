#include "../../arrayADT/logic.c"

/*
    The below function will take an Array ADT as an input and will sort it using Merge sort...
*/

void merger(Array *a, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)calloc(n1, sizeof(int));
    int *R = (int *)calloc(n2, sizeof(int));

    for (i = 0; i < n1; i++){
        L[i] = a->A[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = a->A[m + j + 1];
    }

    i = j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]){
            a->A[k] = L[i];
            i++;
        }
        else{
            a->A[k] = R[j];
            j++;
        }
        k++; 
    }

    while (i < n1)
    {
        a->A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a->A[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    return;
}

void mergeSortArrayADT(Array *a, int l, int r){

    if (l < r)
    {
        int m = l + (r - l)/2;
        mergeSortArrayADT(a, l, m);
        mergeSortArrayADT(a, m + 1, r);
        merger(a, l, m, r);
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

    mergeSortArrayADT(&a, 0, a.length - 1);

    printf("After Sorting:\n");
    display(a);

    return 0;
}