#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"
#include "stack.c"

void init_bst(Tree *t, int n)
{
    t->T = (int *)malloc(n * sizeof(int));
    t->size = n;
    for (int i = 0; i < n; i++)
    {
        t->T[i] = INT_MIN;
    }
    t->length = 0;

    return;
}

// non-recursive insert...
void insert_bst(Tree *t, int data)
{

    int i = 0;
    while (i < t->size && t->T[i] != INT_MIN)
    {
        if (t->T[i] > data)
        {
            i = 2 * i + 1; // left child
        }
        else if (t->T[i] < data)
        {
            i = 2 * i + 2; // right child
        }
        else
        {
            printf("Data already exists!\n");
            return;
        }
    }

    t->T[i] = data;
    t->length++;

    return;
}

// non-recursive inorder, preorder, postorder...

void non_recursive_traverse(Tree t)
{
    printf("Inorder: ");
    inorder(t);
    printf("Preorder: ");
    preorder(t);
    printf("Postorder: ");
    postorder(t);

    return;
}

void inorder(Tree t)
{
    Stack s;
    init(&s, t.length);

    int i = 0, k = t.size, x;

    push(&s, i);

    while (!isEmpty(s))
    {
        i = peek(s);
        if (t.T[k] == INT_MIN || i >= k)
        {
            pop(&s);
            if (isEmpty(s)) continue;
            x = pop(&s);
            printf("%d ", t.T[x]);
            push(&s, x * 2 + 2);
        }
        else
        {
            push(&s, i * 2 + 1);
        }
    }

    printf("\n");

    return;
}
void preorder(Tree t)
{
    return;
}
void postorder(Tree t)
{
    return;
}

// to show levelwise nodes...
void levelwise(Tree t)
{
    if (!t.T)
    {
        printf("Tree is empty...\n");
        return;
    }

    int n = t.length;
    int i = 0;

    while (i < n)
    {
        if (t.T[i] == INT_MIN)
            continue;
        printf("%d ", t.T[i++]);
    }
    printf("\n");

    return;
}

// Check whether BST is a complete tree...
int isComplete(Tree t)
{
    int n = t.length;
    int i = 0;

    while (i < n)
    {
        if (t.T[i] == INT_MIN)
            return 0;
        i++;
    }

    return 1;
}