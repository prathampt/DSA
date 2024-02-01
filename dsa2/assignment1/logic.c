#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void initBST(Tree *t)
{
    *t = NULL;
    return;
}

Node *generateNode(int MIS, char *name)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return NULL;

    nn->MIS = MIS;
    nn->name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(nn->name, name);
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

void insertNode(Tree *t, int MIS, char *name)
{
    // Using recursion...
    if (!*t)
    {
        *t = generateNode(MIS, name);
        return;
    }

    Node *p = *t;

    if (p->MIS > MIS)
    {
        if (p->left == NULL)
        {
            p->left = generateNode(MIS, name);
            return;
        }
        insertNode(&p->left, MIS, name);
        return;
    }
    if (p->MIS < MIS)
    {
        if (p->right == NULL)
        {
            p->right = generateNode(MIS, name);
            return;
        }
        insertNode(&p->right, MIS, name);
        return;
    }
    printf("The student already Exists!\n");
    return;
}

int count(Tree t)
{
    if (!t)
        return 0;

    return 1 + count(t->left) + count(t->right);
}

void removeNode(Tree *t, int MIS)
{
    if (!*t)
        return;

    Node *p = *t, *q = *t;
    char direction;

    while (p->MIS != MIS)
    {
        q = p;
        if (p->MIS > MIS)
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
        {
            *t = p->right;
            printf("The root is replaced by %d\n", p->right->MIS);
        }
        else
        {
            if (direction == 'r')
                q->right = p->right;
            else
                q->left = p->right;
        }
        free(p);
        return;
    }
    if (p->right == NULL)
    {
        if (p == q)
        {
            *t = p->left;
            printf("The root is replaced by %d\n", p->left->MIS);
        }
        else
        {
            if (direction == 'r')
                q->right = p->left;
            else
                q->left = p->left;
        }
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
    p->MIS = q->MIS;
    p->name = q->name;
    if (p == *t)
    {
        printf("The root is replaced by %d\n", q->MIS);
    }
    if (direction == 'l')
        r->left = q->right;
    else
        r->right = q->right;
    free(q);

    return;
}

int search(Tree t, int MIS)
{
    // Using recursion...
    if (!t)
        return 0;

    if (t->MIS == MIS)
        return 1;

    if (t->MIS > MIS)
        return search(t->left, MIS);

    if (t->MIS < MIS)
        return search(t->right, MIS);
}

void preorderTraversal(Tree t)
{
    // NLR...
    if (!t)
        return;

    printf("%d %s\n", t->MIS, t->name);
    preorderTraversal(t->left);
    preorderTraversal(t->right);

    return;
}

void inorderTraversal(Tree t)
{
    // LNR...
    if (!t)
        return;

    inorderTraversal(t->left);
    printf("%d %s\n", t->MIS, t->name);
    inorderTraversal(t->right);

    return;
}

void postorderTraversal(Tree t)
{
    // LRN...
    if (!t)
        return;

    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d %s\n", t->MIS, t->name);

    return;
}