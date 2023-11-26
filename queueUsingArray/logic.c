#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void init(Queue *q, int size){

    q->front = q->rear = -1;
    q->size = size;
    q->Q = (int *)malloc(size * sizeof(int));

    return;
}

void enQueue(Queue *q, int data){
    if (isFull(*q)) return;

    if (isEmpty(*q)) q->front = 0;

    q->Q[++q->rear] = data;

    return;
}

int deQueue(Queue *q){
    if (isEmpty(*q)) return INT_MIN;

    return q->Q[q->front++];    
}

int isEmpty(Queue q){
    if (q.front == -1) return 1;
    return 0;
}

int isFull(Queue q){
    if (q.rear == q.size - 1) return 1;
    return 0;
}

int peek(Queue q){
    if (isEmpty(q)) return INT_MIN;

    return q.Q[q.front]; 
}

void display(Queue q){
    if (isEmpty(q)) return;

    printf("Printing the Queue: ");

    for (int i = q.front; i < q.rear + 1; i++)
    {
        printf("%d | ", q.Q[i]);
    }
    
    printf("\b\b\b   \n");
}