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

int removeNode(List *l, Node *n){
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

    while (p->next->next != n)
    {
        p = p->next;
    }
    
    q = p->next;
    p->next = p->next->next;

    removedElement = q->data;
    free(q);
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

void swapNodes(List * l, Node * n1, Node * n2){
    if (n1 == n2 || !n1 || !n2 || !(*l)) return;

    List * master = l;

    while ((*master) != n1)
    {
        master = &(*master)->next;
    }

    (*master) = n2;

    master = &n1->next;

    while ((*master) != n2)
    {
        master = &(*master)->next;
    }

    (*master) = n1;

    Node * temp = n1->next;
    n1->next = n2->next;
    n2->next = temp;

    return;    
}

void fill(List *l, int number){
    if (number < 1) return;

    for (int i = 0; i < number; i++)
    {
        append(l, rand() % 100 + 1);
    }

    return;    
}

void reverseEven(List *l){
    if (length(*l) - 2 < 0) return;

    Node * p = *l, *q, *r, *s;

    while (p->next)
    {
        q = r = s = NULL;
        if (p->data % 2 == 0){
            q = p;
            r = p;
        }
        else if (p->next->data % 2 == 1){
            p = p->next;
            continue;
        }
        else {
            q = p->next;
            r = q;
        }

        while (r->next->data % 2 == 0)
        {
            r = r->next;
        }

        if (q == r){
            p = r->next;
            continue;
        }
        else s = q->next;

        if (q == p){
            *l = r;
        }
        else {
            p->next = r;
        }

        q->next = r->next;
        p = q;
        q = s;
        s = s->next;

        while (p != r)
        {
            q->next = p;
            p = q;
            q = s;
            s = s->next;
        }
        
        p = q;       
    }

    return;
    
}

int isPalindrome(List l){
    int len = length(l);
    int halfLength = len / 2;

    if (len - 2 < 0) return 1;

    int * arr = (int *) malloc(halfLength * sizeof(int));

    Node * p = l;

    for (int i = 0; i < halfLength; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }

    if (len % 2 == 1) p = p->next;

    for (int i = halfLength - 1; i >= 0; i--)
    {
        if (arr[i] != p->data) return 0;
        p = p->next;
    }
    
    return 1; 
}

void removeDuplicates(List *l){
    int len = length(*l);

    int * arr = (int *) calloc(len, sizeof(int));

    if (!arr) return;

    int count = 0;

    Node * p = *l;

    arr[count++] = p->data;

    while (p->next)
    {
        int data = p->next->data;
        int dublicate = 0;

        for (int i = 0; i < count; i++)
        {
            if (arr[i] == data){
                dublicate = 1;
                break;
            }
        }

        if (dublicate)
        {
            Node * q = p->next;
            p->next = p->next->next;
            free(q);
        }
        else{
            arr[count++] = data;
            p = p->next;
        }
    }

}

void destroy(List *l){
    if (!*l) return;

    while (*l)
    {
        removeBeginning(l);
    }

    return;
}

void removeAndInsert(List *l, Node *n, int index){
    if (!*l) return;    

    Node *p = *l;

    while (p->next != n)
    {
        p = p->next;
    }

    p->next = n->next;

    if (!index)
    {
        n->next = *l;
        *l = n;
        return; 
    }
    
    Node *q = *l;

    for (int i = 0; i < index - 1; i++)
    {
        q = q->next;
    }

    n->next = q->next;
    q->next = n;

    return;
    
}