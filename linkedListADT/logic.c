#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(List *l){
    *l = NULL;
    return;
}

void display(List l){
    printf("Linked list:   ");

    while (l)
    {
        printf(" %d ->", l->data);
        l = l->next;
    }
    printf("\b\b   \n");

    return;
    
}

void append(List *l, int data){
    Node * newNode = (Node *) malloc(sizeof(Node));

    if (!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if (!*l)
    {
        *l = newNode;
        return;
    }

    Node *p = *l;

    while (p->next)
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
    
    *l = newNode;
    return;
}

int removeEnd(List *l){
    Node *p, *q;
    int removedElement;

    if (!*l) return -1;

    p = *l;

    if (!p->next)
    {
        removedElement = p->data;
        *l = NULL;
        free(p);
        return removedElement;
    }

    while (p->next->next)
    {
        p = p->next;
    }
    
    q = p->next;
    p->next = NULL;

    removedElement = q->data;
    free(q);
    return removedElement;    
}

int removeBeginning(List *l){
    Node *p;
    int removedElement;

    p = *l;

    *l = (*l)->next;

    removedElement = p->data;
    free(p);
    return removedElement;
}

void addNodeAtPosition(List *l, int data, int position){
    Node *newNode, *p;
    int i;

    if (position < 0 || position > length(*l)) return;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0)
    {
        newNode->next = *l;
        *l = newNode;
    }
    else
    {
        p = *l;
        for(i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    return;
}

int length(List l){
    Node *p = l;
    int count = 0;

    while(p){
        count++;
        p = p->next;
    }

    return count;
}

void deleteList(List *l){
    Node *current = *l;
    Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *l = NULL;
}
