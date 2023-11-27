#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void init(List *l){
    *l = NULL;
    return;
}

void display(List l){
    printf("Circular Linked list:   ");

    if (!l) return;

    Node * p = l;
    printf(" %d ->", l->data);
    p = p->next;

    while (p != l)
    {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf("\b\b   \n");

    return;
}

void append(List *l, int data){
    Node * newNode = (Node *) malloc(sizeof(Node));

    if (!newNode) return;

    newNode->data = data;
    newNode->next = *l;

    if (!*l)
    {
        *l = newNode;
        newNode->next = newNode;
        return;
    }

    Node *p = *l;

    while (p->next != *l)
    {
        p = p->next;
    }

    p->next = newNode;
    return;
}

void insertAtBeginning(List *l, int data){
    Node * newNode = (Node *) malloc(sizeof(Node));

    if (!newNode) return;

    newNode->data = data;
    newNode->next = *l;

    if (!*l)
    {
        *l = newNode;
        newNode->next = newNode;
        return;
    }

    Node *p = *l;

    while (p->next != *l)
    {
        p = p->next;
    }

    p->next = newNode;
    *l = newNode;
    return;
}

int removeEnd(List *l){
    Node *p, *q;
    int removedElement;

    if (!*l) return INT_MIN;

    p = *l;

    if (p->next == *l)
    {
        removedElement = p->data;
        *l = NULL;
        free(p);
        return removedElement;
    }

    while (p->next->next != *l)
    {
        p = p->next;
    }
    
    q = p->next;
    p->next = *l;

    removedElement = q->data;
    free(q);
    return removedElement;    
}

int removeBeginning(List *l){
    Node *p, *q;
    int removedElement;

    if (!*l) return -1;

    p = *l;

    if (p->next == *l)
    {
        removedElement = p->data;
        *l = NULL;
        free(p);
        return removedElement;
    }

    while (p->next != *l)
    {
        p = p->next;
    }
    
    q = p->next;
    p->next = p->next->next;
    *l = p->next;

    removedElement = q->data;
    free(q);
    return removedElement;
}

int length(List l){
    if (l == NULL) return 0;

    Node *p = l->next;
    int count = 1;

    while(p != l){
        count++;
        p = p->next;
    }

    return count;
}

void fill(List *l, int number){
    if (number < 1) return;

    for (int i = 0; i < number; i++)
    {
        append(l, rand() % 100 + 1);
    }

    return;    
}

void destroy(List *l){
    if (!*l) return;

    Node *p = (*l)->next;
    (*l)->next = NULL;    
    
    while (p != *l){
        Node *q = p;
        p = p->next;
        free(q);
    }

    free(p);
    *l = NULL;
    return;
}