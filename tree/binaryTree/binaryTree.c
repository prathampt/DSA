#include "stack.c"

void init(Tree *t)
{
    *t = NULL;
    return;
}

Node *generateNode(char * string)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return NULL;

    nn->s = (char *)malloc(sizeof(char) * strlen(string));
    strcpy(nn->s, string);
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

void inorderTraversal(Tree t)
{
    if (!t)
        return;

    inorderTraversal(t->left);
    printf("%s ", t->s);
    inorderTraversal(t->right);

    return;
}
