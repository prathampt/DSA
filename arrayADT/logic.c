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
    int length = arr->length;

    for (int i = length; i < arr->size; i++){
        arr->A[i] = rand() % 100 + 1;
    }

    arr->length = arr->size;
    return;    
}

void display(Array arr){
    int length = arr.length;

    printf("Array: [");

    for (int i = 0; i < length; i++)
    {
        printf("%d, ", arr.A[i]);
    }

    printf("\b\b ]\n");
    return;
    
}

void append(Array *arr, int element){
    if (arr->length == arr->size) return;

    arr->A[arr->length++] = element;
    return;    
}

void insert(Array *arr, int element, int position){
    int length = arr->length, temp;

    if (length == arr->size || position < 0 || position >= length) return;

    for (int i = length + 1; i > position; i--)
    {
        arr->A[i] = arr->A[i-1];
    }

    arr->A[position] = element;

    arr->length++;
    return;
}

int removeElement(Array *arr, int element);
int removeAtIndex(Array *arr, int index);
void reverse(Array *arr);
int min(Array arr);
int max(Array arr);
Array * merge(Array arr1, Array arr2);
void sort(Array *arr);
