#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(Tree *t)
{
    *t = NULL;
    return;
}

Node *generateNode(int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return NULL;

    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

void preorderTraversal(Tree t)
{ // NLR...
    if (!t)
        return;

    printf("%d ", t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);

    return;
}

void inorderTraversal(Tree t)
{ // LNR...
    if (!t)
        return;

    inorderTraversal(t->left);
    printf("%d ", t->data);
    inorderTraversal(t->right);

    return;
}

void postorderTraversal(Tree t)
{ // LRN...
    if (!t)
        return;

    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d ", t->data);

    return;
}

int count(Tree t)
{ // This counts the number of nodes in the tree...
    if (!t)
        return 0;

    return 1 + count(t->left) + count(t->right);
}

void insert(Tree *t, int data)
{
    if (!*t)
    {
        *t = generateNode(data);
        return;
    }

    Node *p = *t, *q = NULL;

    while (p)
    {
        q = p;
        if (p->data > data)
        {
            p = p->left;
        }
        else if (p->data < data)
        {
            p = p->right;
        }
        else
        {
            printf("The element already exists!\n");
            return;
        }
    }

    if (data > q->data)
        q->right = generateNode(data);
    else
        q->left = generateNode(data);

    return;
}

int search(Tree t, int data)
{
    if (!t)
        return 0;

    if (t->data == data)
        return 1;

    Node *p = t;

    while (p)
    {
        if (p->data == data)
            return 1;
        else if (p->data > data)
            p = p->left;
        else
            p = p->right;
    }

    return 0;
}

void delete(Tree *t, int data)
{
    if (!*t)
        return;

    Node *p = *t, *q = *t;
    char direction;

    while (p->data != data)
    {
        q = p;
        if (p->data > data)
        {
            p = p->left;
            direction = 'l'; // p is left child of q
        }
        else
        {
            p = p->right;
            direction = 'r'; // p is right child of q
        }
    }

    // Handling the case when the node to be deleted has no child...
    if (p->left == NULL && p->right == NULL)
    {
        if (p == q)
        {
            *t = NULL;
            free(p);
            printf("The tree is empty now...\n");
            return;
        }
        free(p);
        if (direction == 'r')
            q->right = NULL;
        else
            q->left = NULL;
        return;
    }

    // Handling the case when the node has only one child...
    if (p->left == NULL)
    {
        if (p == q)
            *t = p->right;
        else if (direction == 'r')
            q->right = p->right;
        else
            q->left = p->right;
        free(p);
        return;
    }
    if (p->right == NULL)
    {
        if (p == q)
            *t = p->left;
        else if (direction == 'r')
            q->right = p->left;
        else
            q->left = p->left;
        free(p);
        return;
    }

    // Handling the case when the node has two childrens...
    // Checking for the smallest number in the right sub tree...
    q = p->right;
    Node *r = p;
    direction = 'r';
    while (q->left)
    {
        r = q;
        direction = 'l';
        q = q->left;
    }
    p->data = q->data;
    if (direction == 'l')
        r->left = q->right;
    else
        r->right = q->right;
    free(q);

    return;
}