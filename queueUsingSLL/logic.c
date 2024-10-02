#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void init(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue *q, int data){
    Node * nn = (Node *)malloc(sizeof(Node));

    if(!nn) return;
    
    nn->data = data;
    nn->next = NULL;

    if (isEmpty(*q)){
        q->front = nn;
        q->rear = nn;
        return;
    }

    q->rear->next = nn;
    q->rear = nn;
    return;    
}

int deQueue(Queue *q){
    if (isEmpty(*q)) return INT_MIN;

    Node *p = q->front;
    int data = p->data;

    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }else{
        q->front = q->front->next;
    }

    free(p);

    return data;
}

int isEmpty(Queue q){
    if (!q.front) return 1;
    return 0;
}

int peek(Queue q){
    if (isEmpty(q)) return INT_MIN;

    return q.front->data;
}

void display(Queue q){
    if (isEmpty(q)) return;

    printf("Displaying the queue: ");

    Node *p = q.front;

    while (p){
        printf("%d | ", p->data);
        p = p->next;
    }
    
    printf("\b\b\b   \n");
    return;
}