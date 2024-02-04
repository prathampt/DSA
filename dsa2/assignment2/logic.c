#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "header.h"
#include "stack.c"
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

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
        if (t.T[i] == INT_MIN || i >= k)
        {
            pop(&s);
            if (isEmpty(s))
                break;
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

    int n = t.size;
    int i = 0;
    int j = 0, k = 1;
    int levelCount = 1;
    int treeHeight = height(t);

    for (int z = 0; z < pow(2, (treeHeight - levelCount)) - 1; z++)
    {
        printf("    ");
    }
    printf("  ");

    while (i < n)
    {
        if (j == k)
        {
            printf("\n\n");
            levelCount++;
            for (int z = 0; z < pow(2, (treeHeight - levelCount)) - 1; z++)
            {
                printf("    ");
            }
            if (treeHeight != levelCount - 1)
                printf("  ");
            j = 0;
            k *= 2;
        }
        if (t.T[i] == INT_MIN)
        {
            i++;
            j++;
            printf("    ");
            continue;
        }
        printf("%4d", t.T[i++]);
        for (int z = 0; z < pow(2, (treeHeight - levelCount + 1)) - 1; z++)
        {
            printf("    ");
        }
        j++;
    }
    printf("\n");

    return;
}

// Check whether BST is a complete tree...
// To be modified...
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

int levels(Tree t, int i)
{

    if (!t.T)
        return 0;
    if (t.length == 1)
        return 0;
    if (i >= t.size)
        return 0;
    if (t.T[i] == INT_MIN)
        return 0;

    return 1 + MAX(levels(t, 2 * i + 1), levels(t, 2 * i + 2));
}

int height(Tree t)
{
    return levels(t, 0) - 1;
}