#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "header.h"

void init_bst(Tree *t, int n)
{
    t->T = (int *)malloc(n * sizeof(int));
    t->size = n;
    for (int i = 0; i < n; i++)
    {
        t->T[i] = INT_MIN;
    }

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

    return;
}

void non_recursive_traverse(Tree t); // non-recursive inorder, preorder, postorder...

void inorder(Tree t)
{
    return;
}
void preorder(Tree t);
void postorder(Tree t);

void levelwise(Tree t);  // to show levelwise nodes...
void isComplete(Tree t); // Check whether BST is a complete tree...
