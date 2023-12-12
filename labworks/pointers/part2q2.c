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
    node *head=NULL;
    node *end = head;
    while (1)
    {
        scanf("%c", &c);
        if (c == ' ')
            break;
        
        node* newNode=(node* )malloc(sizeof(node));
        newNode->data = c;
        if (head==NULL)
        {
            newNode->p=newNode;
            head=newNode;
            end=head;
            continue;
        }
        
        newNode->p = end->p;
        end->p = newNode;
        end = end->p;
    }
    node *p = head;
    printf("%c ", p->data);
    p = head->p;

    for (; head != p;)
    {
        printf("%c ", p->data);
        p = p->p;
    }

    return 0;
}
