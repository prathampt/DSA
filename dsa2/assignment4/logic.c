#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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

    node->balancingFactor = height(node->left) - height(node->right);

    while (node->parent)
    {
        node = node->parent;

        int t = height(node->left) - height(node->right);
        node->balancingFactor = t;
    }

    return;
}

void insertNode(AVLtree *t, char *name)
{
    if (!*t)
    {
        *t = generateNode(name);
        balanceFactor(*t);
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
    adjustImbalance(t, p->parent);

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
        free(p);

        balanceFactor(q);
        adjustImbalance(t, q->parent);

        return;
    }

    // Handling the case when the node has only one child...
    if (p->left == NULL)
    {
        if (p == q)
        {
            *t = p->right;
            p->right->parent = NULL;
            printf("The root is replaced by %s\n", p->right->name);
        }
        else
        {
            if (direction == 'r')
                q->right = p->right;
            else
                q->left = p->right;

            p->right->parent = q;
        }
        free(p);

        balanceFactor(q);
        adjustImbalance(t, q->parent);

        return;
    }
    if (p->right == NULL)
    {
        if (p == q)
        {
            *t = p->left;
            p->left->parent = NULL;
            printf("The root is replaced by %s\n", p->left->name);
        }
        else
        {
            if (direction == 'r')
                q->right = p->left;
            else
                q->left = p->left;

            p->left->parent = q;
        }
        free(p);

        balanceFactor(q);
        adjustImbalance(t, q->parent);

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

    strcpy(p->name, q->name);

    if (p == *t)
    {
        printf("The root is replaced by %s\n", q->name);
    }
    if (direction == 'l')
        r->left = q->right;
    else
        r->right = q->right;

    if (q->right)
        q->right->parent = r;

    free(q);

    balanceFactor(r);
    adjustImbalance(t, r->parent);

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

void destroyTree(AVLtree *t)
{
    if (!*t)
        return;

    if (!(*t)->right && !(*t)->left)
    {
        free(*t);
        *t = NULL;
        return;
    }

    if (!(*t)->right)
    {
        destroyTree(&(*t)->left);
        free(*t);
        *t = NULL;
        return;
    }

    if (!(*t)->left)
    {
        destroyTree(&(*t)->right);
        free(*t);
        *t = NULL;
        return;
    }

    destroyTree(&(*t)->left);
    destroyTree(&(*t)->right);
    free(*t);
    *t = NULL;
    return;
}

int height(AVLtree t)
{
    if (!t)
        return 0;

    return 1 + MAX(height(t->left), height(t->right));
}

void RL(AVLtree *t, Node *n)
{
    RR(t, n->left);
    LL(t, n);
    return;
}

void LR(AVLtree *t, Node *n)
{
    LL(t, n->right);
    RR(t, n);
    return;
}

void LL(AVLtree *t, Node *n)
{
    Node *temp = n->left;
    n->left = temp->right;
    if (n->left)
        n->left->parent = n;

    temp->right = n;
    temp->parent = n->parent;
    n->parent = temp;

    if (temp->parent)
    {
        if (temp->parent->left == n)
            temp->parent->left = temp;
        else
            temp->parent->right = temp;
    }
    else
        *t = temp;
    balanceFactor(n);
    balanceFactor(temp);

    return;
}

void RR(AVLtree *t, Node *n)
{
    Node *temp = n->right;
    n->right = temp->left;
    if (n->right)
        n->right->parent = n;

    temp->left = n;
    temp->parent = n->parent;
    n->parent = temp;

    if (temp->parent)
    {
        if (temp->parent->right == n)
            temp->parent->right = temp;
        else
            temp->parent->left = temp;
    }
    else
        *t = temp;
    balanceFactor(n);
    balanceFactor(temp);

    return;
}

void adjustImbalance(AVLtree *t, Node *n)
{

    if (!n)
        return;

    int bf = n->balancingFactor;

    while (bf == 0 | bf == 1 | bf == -1)
    {
        n = n->parent;
        if (!n)
            return;
        bf = n->balancingFactor;
    }

    if (bf == 2)
    {
        if (n->left->balancingFactor == -1)
            RL(t, n);
        else
            LL(t, n);
    }
    else if (bf == -2)
    {
        if (n->right->balancingFactor == 1)
            LR(t, n);
        else
            RR(t, n);
    }

    return adjustImbalance(t, n->parent);
}
