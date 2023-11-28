#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void init(Stack *s){
    *s = NULL;
    return;
}

int isEmpty(Stack s){
    if (!s) return 1;
    return 0;
}

void push(Stack *s, int data){
    Node * nn = (Node *)malloc(sizeof(Node));
    if (!nn) return;

    nn->data = data;
    nn->next = *s;
    *s = nn;   

    return;
}

int pop(Stack *s){
    if (isEmpty(*s)) return INT_MIN;

    Node * q = *s;
    *s = (*s)->next;

    int data = q->data;
    free(q);
    return data;
}

int peek(Stack s){
    if (isEmpty(s)) return INT_MIN;

    return s->data;
}

void display(Stack s){
    if (isEmpty(s)) return;

    printf("Displaying stack form top to bottom: ");

    while (s){
        printf("%d | ", s->data);
        s = s->next;
    }
    printf("\b\b\b   \n");

    return;
}