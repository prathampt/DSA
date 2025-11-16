#include "binaryTree.h"

typedef struct snode{
    Node * n;
    struct snode * next;
} SNode;

typedef SNode * Stack;

void Sinit(Stack *s);
int isEmpty(Stack s);
void push(Stack *s, Node * n);
Node * pop(Stack *s);
Node * peek(Stack s);