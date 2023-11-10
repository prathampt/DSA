#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(List *l){
    l->front = NULL;
    l->rear = NULL;
    return;
}

void append(List *l, int data){
    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->front) {
        l->front = nn;
        l->rear = nn;
    }
    else {
        nn->previous = l->rear;
        l->rear->next = nn;
        l->rear = nn;
    }

    return;
}

void insertAtBeginning(List *l, int data){
    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->front) {
        l->front = nn;
        l->rear = nn;
    }
    else {
        nn->next = l->front;
        l->front->previous = nn;
        l->front = nn;
    }

    return;
}

void insertAtIndex(List *l, int data, int index){
    if (index < 0) return;
    else if (index == 0) {
        insertAtBeginning(l, data);
        return;
    }

    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    Node * p = l->front;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    p->next->previous = nn;
    nn->next = p->next;
    p->next = nn;
    nn->previous = p;

    return;
}

int removeEnd(List *l){
    Node *p = l->rear;

    l->rear = l->rear->previous;
    l->rear->next = NULL;

    int data = p->data;

    free(p);

    return data;
}

int removeBeginning(List *l){
    Node *p = l->front;

    l->front = l->front->next;
    l->front->previous = NULL;

    int data = p->data;

    free(p);

    return data;
}

int removeAtIndex(List *l, int index){
    if (index < 0) return;
    else if (index == 0) {
        return removeBeginning(l);
    }

    Node * p = l->front;

    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }

    p->previous->next = p->next;
    p->next->previous = p->previous;

    int data = p->data;

    free(p);

    return data;
}

int removeNode(List *l, Node * n){
    n->previous->next = n->next;
    n->next->previous = n->previous;

    int data = n->data;

    free(n);

    return data;
}

void display(List l){
    if (!l.front) return;

    printf("Displaying the linked list: ");

    while (l.front)
    {
        printf("%d <-> ", l.front->data);
        l.front = l.front->next;
    }

    printf("\b\b\b\b     \n");

    return;  
}

int length(List l){
    int count = 0;

    while (l.front)
    {
        count++;
        l.front = l.front->next;
    }
    
    return count;
}

void fill(List *l, int numberOfNodes);
void swapNodes(List *l, Node *n1, Node *n2);