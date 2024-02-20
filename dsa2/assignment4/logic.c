#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void init(AVLtree *t)
{
    *t = NULL;
    return;
}

Node *generateNode(char *name)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    if (!nn)
        return NULL;

    nn->balancingFactor = 0;
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    nn->name = (char *)malloc(strlen(name) + 1);
    strcpy(nn->name, name);

    return nn;
}

void balanceFactor(Node *node)
{
    if (!node)
        return;

    node->balancingFactor = 0;

    while (node->parent)
    {
        if (node->parent->left == node)
        {
            node->parent->balancingFactor += 1;
        }
        else
        {
            node->parent->balancingFactor -= 1;
        }

        node = node->parent;
    }

    return;
}

void reverseBalanceFactor(Node *node)
{
    if (!node)
        return;

    node->balancingFactor = 0;

    while (node->parent)
    {
        if (node->parent->left == node)
        {
            node->parent->balancingFactor -= 1;
        }
        else
        {
            node->parent->balancingFactor += 1;
        }

        node = node->parent;
    }

    return;
}

void insertNode(AVLtree *t, char *name)
{
    if (!*t)
    {
        *t = generateNode(name);
        return;
    }

    Node *p = *t;
    Node *q = NULL;
    char direction;

    while (p)
    {
        q = p;
        if (strcmp(name, p->name) > 0)
        {
            p = p->right;
            direction = 'r';
        }
        else if (strcmp(name, p->name) < 0)
        {
            p = p->left;
            direction = 'l';
        }
        else
        {
            printf("The element already exists in the tree!\n");
            return;
        }
    }

    p = generateNode(name);

    if (direction == 'r')
        q->right = p;
    else
        q->left = p;

    p->parent = q;

    balanceFactor(p);

    return;
}

void removeNode(AVLtree *t, char *name)
{
    if (!*t)
        return;

    Node *p = *t, *q = *t;
    char direction;

    while (strcmp(name, p->name) != 0)
    {
        q = p;
        if (strcmp(name, p->name) < 0)
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

        if (direction == 'r')
            q->right = NULL;
        else
            q->left = NULL;
        reverseBalanceFactor(p);
        free(p);
        return;
    }

    // Handling the case when the node has only one child...
    if (p->left == NULL)
    {
        if (p == q)
        {
            *t = p->right;
            printf("The root is replaced by %s\n", p->right->name);
        }
        else
        {
            if (direction == 'r')
                q->right = p->right;
            else
                q->left = p->right;
        }
        reverseBalanceFactor(p);
        free(p);
        return;
    }
    if (p->right == NULL)
    {
        if (p == q)
        {
            *t = p->left;
            printf("The root is replaced by %s\n", p->left->name);
        }
        else
        {
            if (direction == 'r')
                q->right = p->left;
            else
                q->left = p->left;
        }
        reverseBalanceFactor(p);
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

    p->name = q->name;
    if (p == *t)
    {
        printf("The root is replaced by %s\n", q->name);
    }
    if (direction == 'l')
        r->left = q->right;
    else
        r->right = q->right;
    reverseBalanceFactor(q);
    free(q);

    return;
}

void traverse(AVLtree t) // Display name, parent and the balancing factor of each node...
{
    if (!t)
        return;

    traverse(t->left);
    printf("Name: %s\nParent Name: %s\nBalancing Factor: %d\n\n", t->name, (t->parent) ? t->parent->name : "NULL", t->balancingFactor);
    traverse(t->right);

    return;
}

void destroyTree(AVLtree *t){
    if (!*t) return;

    if (!(*t)->right && !(*t)->left){
        free(*t);
        *t == NULL;
        return;
    }

    if (!(*t)->right){
        destroyTree(&(*t)->left);
        free(*t);
        *t == NULL;
        return;
    }

    if (!(*t)->left){
        destroyTree(&(*t)->right);
        free(*t);
        *t == NULL;
        return;
    }

    destroyTree(&(*t)->left);
    destroyTree(&(*t)->right);
    free(*t);
    *t = NULL;
    return;
}