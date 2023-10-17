#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Array *arr, int size){
    arr->A = (int *) malloc(size*sizeof(int));
    if(!arr->A) return;

    arr->size = size;
    arr->length = 0;
    return;
}

void fill(Array * arr){
    for (int i = arr->length; i < arr->size; i++){
        arr->A[i] = rand() % 100 + 1;
    }

    return;    
}

void display(Array arr){
    printf("Array: [");

    for (int i = 0; i < arr.length; i++)
    {
        printf("%d, ", arr.A[i]);
    }

    printf("\b\b ]");
    return;
    
}

void append(Array *arr, int element);
void insert(Array *arr, int element, int position);
void removeElement(Array *arr, int element);
void removeAtIndex(Array *arr, int index);
void reverse(Array *arr);
int min(Array arr);
int max(Array arr);
Array * merge(Array arr1, Array arr2);
