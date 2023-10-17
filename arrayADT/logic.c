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

    printf("\b\b]\n");
    return;
    
}

void append(Array *arr, int element){
    if (arr->length == arr->size) return;

    arr->A[arr->length++] = element;
    return;    
}

void insert(Array *arr, int element, int position){
    int length = arr->length;

    if (length == arr->size || position < 0 || position >= length) return;

    for (int i = length + 1; i > position; i--)
    {
        arr->A[i] = arr->A[i-1];
    }

    arr->A[position] = element;

    arr->length++;
    return;
}

int removeElement(Array *arr, int element){
    int removedIndex = -1, flag = 0, length = arr->length;

    for (int i = 0; i < length; i++)
    {

        if (flag)
        {
            arr->A[i - 1] = arr->A[i];
        }
        
        else if (arr->A[i] == element)
        {
            flag = 1;
            removedIndex = i;
        }
        
    }

    if (removedIndex == -1)
    {
        return removedIndex;
    }
    
    arr->A[length-1] = 0;
    arr->length--;

    return removedIndex;
    
}

int removeAtIndex(Array *arr, int index){
    int removedElement = arr->A[index], length = arr->length;

    if (index < 0 || index >= length)
    {
        return -1;
    }
    
    for (int i = index; i < length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[length-1] = 0;
    arr->length--;

    return removedElement;
}

void reverse(Array *arr){
    int length = arr->length, temp;

    for (int i = 0; i < length/2; i++)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[length - i - 1];
        arr->A[length - i - 1] = temp;
    }
    
    return;
}

int min(Array arr){
    int min = arr.A[0], length = arr.length;

    for (int i = 1; i < length; i++)
    {
        if (min > arr.A[i])
        {
            min = arr.A[i];
        }
        
    }
    
    return min;
}

int max(Array arr){
    int max = arr.A[0], length = arr.length;

    for (int i = 1; i < length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i];
        }
        
    }
    
    return max;
}

Array join(Array arr1, Array arr2){
    Array joined;
    int length1 = arr1.length, length2 = arr2.length;

    init(&joined, length1 + length2);

    for (int i = 0; i < length1; i++)
    {
        append(&joined, arr1.A[i]);
    }

    for (int i = 0; i < length2; i++)
    {
        append(&joined, arr2.A[i]);
    }
    
    return joined;
}

void sort(Array *arr){
    int length = arr->length, min, temp;

    for (int i = 0; i < length; i++)
    {   
        min = i;
        for (int j = i+1; j < length; j++)
        {
            if (arr->A[min] > arr->A[j])
            {
                min = j;
            }
            
        }
        
        temp = arr->A[min];
        arr->A[min] = arr->A[i];
        arr->A[i] = temp;
    }

    return;    
}
