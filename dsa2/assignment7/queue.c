#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void initQ(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue *q, char data){
    qNode * nn = (qNode *)malloc(sizeof(qNode));

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

char deQueue(Queue *q){
    if (isEmpty(*q)) return CHAR_MIN;

    if(q->front == q->rear) q->rear = NULL;

    qNode *p = q->front;
    q->front = q->front->next;

    int d = p->data;    
    free(p);

    return d;
}

int isEmpty(Queue q){
    if (!q.front) return 1;
    return 0;
}

char peek(Queue q){
    if (isEmpty(q)) return CHAR_MIN;

    return q.front->data;
}

void display(Queue q){
    if (isEmpty(q)) return;

    printf("Displaying the queue: ");

    qNode *p = q.front;

    while (p){
        printf("%c | ", p->data);
        p = p->next;
    }
    
    printf("\b\b\b   \n");
    return;
}