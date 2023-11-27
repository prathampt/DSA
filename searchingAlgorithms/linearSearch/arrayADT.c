#include "../../arrayADT/logic.c"
#include <limits.h>

int linearSearch(Array a, int data){
    if (a.length == 0) return INT_MIN;

    int len = a.length;

    for (int i = 0; i < len; i++){
        if (a.A[i] == data){
            return i;
        }        
    }

    return INT_MIN;    
}

int main(){
    Array arr;
    init(&arr, 10);
    fill(&arr);

    display(arr);

    int p;

    if ((p = linearSearch(arr, 87)) == INT_MIN){
        printf("Element doesn't exist!\n");
        return 0;
    }
    printf("Index of element %d is %d\n", 87, p);

    return 0;
}