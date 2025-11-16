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
    printf("Inorder Printing: ");
    inorder(t);
    printf("\n");
    printf("Preorder Printing: ");
    preorder(t);
    printf("\n");
    printf("Postorder Printing: ");
    postorder(t);
    printf("\n");

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

// Preorder using only one stack...
void preorder(Tree t)
{   
    Stack s;
    init(&s, t.length);
    int i = 0;
    int k = t.size;

    printf("%d ", t.T[i]);
    push(&s, 2 * i + 2);
    i = 2 * i + 1;

    while(!isEmpty(s) && i < k){
        
        while (i != INT_MIN && t.T[i] == INT_MIN && i < k){
            i = pop(&s);
        }
        if (i == INT_MIN) break;
        printf("%d ", t.T[i]);
        push(&s, 2 * i + 2);
        i = 2 * i + 1;
    }

    printf("\n");
    return;
}
void postorder(Tree t)
{   
    Stack s1, s2;
    init(&s1, t.length);
    init(&s2, t.length + 2);

    int i = 0, k = t.size;
    push(&s1, i);

    while (!isEmpty(s1) && i < k)
    {
        i = pop(&s1);
        while (i != INT_MIN && i < k && t.T[i] == INT_MIN)
        {
            i = pop(&s1);
        }
        if (i == INT_MIN) break;
        push(&s2, i);
        push(&s1, 2 * i + 1);
        push(&s1, 2 * i + 2);
    }

    while (!isEmpty(s2))
    {
        printf("%d ", t.T[pop(&s2)]);
    }   

    printf("\n");

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
        if (t.T[i] != INT_MIN)
        {
            printf("%4d", t.T[i++]);
        }
        else
        {
            printf("    ");
            i++;
        }
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
int isComplete(Tree t)
{
    int treeHeight = height(t);
    int i = 0, n = pow(2, treeHeight) - 1;

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