#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    if (!l->rear) return INT_MIN;
    Node *p = l->rear;

    l->rear = l->rear->previous;
    if (!l->rear){
        l->front = NULL;
        return INT_MIN;
    }
    l->rear->next = NULL;

    int data = p->data;

    free(p);

    return data;
}

int removeBeginning(List *l){
    if (!l->front) return INT_MIN;
    Node *p = l->front;

    l->front = l->front->next;
    if (!l->front){
        l->rear = NULL;
        return INT_MIN;
    } 
    l->front->previous = NULL;

    int data = p->data;

    free(p);

    return data;
}

int removeAtIndex(List *l, int index){
    if (index < 0) return INT_MIN;
    else if (index == 0) {
        return removeBeginning(l);
    }

    Node * p = l->front;

    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }

    if (!p->next) return removeEnd(l);

    p->previous->next = p->next;
    p->next->previous = p->previous;

    int data = p->data;

    free(p);

    return data;
}

int removeNode(List *l, Node * n){
    if (n == l->front) return removeBeginning(l);
    else if (n == l->rear) return removeEnd(l);

    n->previous->next = n->next;
    n->next->previous = n->previous;

    int data = n->data;

    free(n);

    return data;
}

void destroy(List *l){
    if (!l->front) return;

    while (l->front)
    {
        removeBeginning(l);
    }
    
    return;
}

void display(List l){
    if (!l.front) return;

    printf("Displaying the linked list: ");

    // Node * p = l.front;
    // while (p)
    // {
    //     printf("%d <-> ", p->data);
    //     p = p->next;
    // }

    for (Node * p = l.front; p != NULL; p = p->next){
        printf("%d <-> ", p->data);
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

void fill(List *l, int numberOfNodes){
    if (numberOfNodes < 1) return;

    for (int i = 0; i < numberOfNodes; i++)
    {
        append(l, rand() % 201 - 100);
    }

    return;    
}

void swapNodes(List *l, Node *n1, Node *n2){
    if (n1 == n2) return;
    else if (n1->next == n2){
        n1->previous->next = n2;
        n2->next->previous = n1;

        Node * p = n2->next;
        n2->next = n1;
        n1->next = p;

        p = n1->previous;
        n1->previous = n2;
        n2->previous = p;

        return;
    }

    if (!n1->previous) l->front = n2;
    else n1->previous->next = n2;
    n1->next->previous = n2;

    if(!n2->next) l->rear = n1;
    else n2->next->previous = n1;
    n2->previous->next = n1;

    Node *p = n1->previous;
    n1->previous = n2->previous;
    n2->previous = p;

    p = n1->next;
    n1->next = n2->next;
    n2->next = p;

    return;
}