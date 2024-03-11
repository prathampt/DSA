#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int isEmptyMax(MaxHeap h)
{
    return (h.rear == -1);
}
int isFullMax(MaxHeap h)
{
    return (h.rear == h.size - 1);
}

int isEmptyMin(MinHeap h)
{
    return (h.rear == -1);
}
int isFullMin(MinHeap h)
{
    return (h.rear == h.size - 1);
}

void initMax(MaxHeap *h, int size)
{
    h->A = (int *)malloc(sizeof(int) * size);
    h->size = size;
    h->rear = -1;
    return;
}

void MaxHeapSort(int *arr, int size)
{
    MaxHeap h;
    initMax(&h, size);

    for (int i = 0; i < size; i++)
    {
        insetMax(&h, arr[i]);
    }

    int i = 0;
    while (!isEmptyMax(h))
    {
        arr[i] = removeMax(&h);
        i++;
    }

    return;
}

void insetMax(MaxHeap *h, int value)
{
    if (isFullMax(*h))
        return;

    h->rear++;
    int i = h->rear;

    while (i > 0 && value > h->A[(i - 1) / 2])
    {
        h->A[i] = h->A[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    h->A[i] = value;

    return;
}

int removeMax(MaxHeap *h)
{
    if (isEmptyMax(*h))
        return INT_MIN;

    int removedElement = h->A[0];
    h->A[0] = h->A[h->rear];
    h->rear--;
    maxHeapify(h, 0);

    return removedElement;
}

void maxHeapify(MaxHeap *h, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->rear && h->A[left] > h->A[largest])
        largest = left;

    if (right < h->rear && h->A[right] > h->A[largest])
        largest = right;

    if (largest != index)
    {
        swap(&h->A[index], &h->A[largest]);
        maxHeapify(h, largest);
    }

    return;
}

void initMin(MinHeap *h, int size)
{
    h->A = (int *)malloc(sizeof(int) * size);
    h->size = size;
    h->rear = -1;
    return;
}

void MinHeapSort(int *arr, int size)
{
    MinHeap h;
    initMin(&h, size);

    for (int i = 0; i < size; i++)
    {
        insetMin(&h, arr[i]);
    }

    int i = 0;
    while (!isEmptyMin(h))
    {
        arr[i] = removeMin(&h);
        i++;
    }

    return;
}

void insetMin(MinHeap *h, int value)
{
    if (isFullMin(*h))
        return;

    h->rear++;
    int i = h->rear;

    while (i > 0 && value < h->A[(i - 1) / 2])
    {
        h->A[i] = h->A[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    h->A[i] = value;

    return;
}

int removeMin(MinHeap *h)
{
    if (isEmptyMin(*h))
        return INT_MIN;

    int removedElement = h->A[0];
    h->A[0] = h->A[h->rear];
    h->rear--;
    minHeapify(h, 0);

    return removedElement;
}

void minHeapify(MinHeap *h, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->rear && h->A[left] < h->A[smallest])
        smallest = left;

    if (right < h->rear && h->A[right] < h->A[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&h->A[index], &h->A[smallest]);
        minHeapify(h, smallest);
    }

    return;
}
