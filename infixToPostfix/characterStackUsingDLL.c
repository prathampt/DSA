#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "characterStackUsingDLL.h"

void init(Stack *s){
    s->base = NULL;
    s->top = NULL;
    return;
}

int isEmpty(Stack s){
    if (s.base == NULL) return 1;

    return 0;
}

void push(Stack *s, char data){
    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (isEmpty(*s))
    {
        s->base = nn;
        s->top = nn;
        return;
    }
    else
    {
        nn->previous = s->top;
        s->top->next = nn;
        s->top = nn;
    }
    
    return;
}

char pop(Stack *s){
    if (isEmpty(*s)) return CHAR_MIN;

    Node *p = s->top;

    s->top = s->top->previous;
    if (s->top) s->top->next = NULL;
    else s->base = NULL;

    char data = p->data;

    free(p);

    return data;
}

char peek(Stack s){
    if (isEmpty(s)) return CHAR_MIN;

    return s.top->data;
}

void display(Stack s){
    if (isEmpty(s)) return;

    printf("Displaying the Stack: ");

    for (Node * p = s.base; p != NULL; p = p->next)
    {
        printf("%c | ", p->data);
    }
    
    printf("\b\b   \n");
    return;
}