#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void Sinit(Stack *s){
    *s = NULL;
    return;
}

int isEmpty(Stack s){
    if (!s) return 1;
    return 0;
}

void push(Stack *s, Node * n){
    SNode * nn = (SNode *)malloc(sizeof(SNode));
    if (!nn) return;

    nn->n = n;
    nn->next = *s;
    *s = nn;   

    return;
}

Node * pop(Stack *s){
    if (isEmpty(*s)) return NULL;

    SNode * q = *s;
    *s = (*s)->next;

    Node *n = q->n;
    free(q);
    return n;
}

Node * peek(Stack s){
    if (isEmpty(s)) return NULL;

    return s->n;
}
