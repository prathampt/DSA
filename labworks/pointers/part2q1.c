#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node *p;
} node;

int main()
{
    printf("Enter space to stop:\n");
    printf("Enter your input Here:\n");
    char c;
    node *ptr;
    node a;
    a.p = &a;
    ptr = &a;
    node *end = &a;
    while (1)
    {
        scanf("%c", &c);
        if (c == ' ')
            break;
        node* newNode=(node* )malloc(sizeof(node));
        newNode->data = c;
        newNode->p = end->p;
        end->p = newNode;
        end = end->p;
    }
    node *p = ptr;
    printf("%c ", p->data);
    p = ptr->p;

    for (; ptr != p;)
    {
        printf("%c ", p->data);
        p = p->p;
    }

    return 0;
}
