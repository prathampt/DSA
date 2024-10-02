#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void init(Queue *q, int size){

    q->front = q->rear = -1;
    q->size = size;
    q->length = 0;
    q->Q = (int *)malloc(size * sizeof(int));

    return;
}

void enQueue(Queue *q, int data){
    if (isFull(*q)) return;

    if (isEmpty(*q)) q->front = 0;
    q->rear = ++q->rear % q->size;
    
    q->Q[q->rear] = data;
    q->length++;
    return;
}

int deQueue(Queue *q){
    if (isEmpty(*q)) return INT_MIN;
    int data = q->Q[q->front];
    q->front = ++q->front % q->size;
    q->length--;
    return data;    
}

int isEmpty(Queue q){
    if (q.length == 0) return 1;
    return 0;
}

int isFull(Queue q){
    if (q.length == q.size) return 1;
    return 0;
}

int peek(Queue q){
    if (isEmpty(q)) return INT_MIN;

    return q.Q[q.front]; 
}

void display(Queue q){
    if (isEmpty(q)) return;

    printf("Printing the Queue: ");

    for (int i = q.front; i < q.front + q.length; i++)
    {
        printf("%d | ", q.Q[i % q.size]);
    }
    
    printf("\b\b\b   \n");
}