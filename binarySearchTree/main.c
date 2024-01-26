#include <stdio.h>
#include "logic.c"

int main()
{
    Tree t;
    init(&t);

    char c;

    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
            continue;
        insert(&t, c - '0');
    }

    printf("Preorder: ");
    preorderTraversal(t);
    printf("\n");
    printf("Inorder: ");
    inorderTraversal(t);
    printf("\n");
    printf("Postorder: ");
    postorderTraversal(t);
    printf("\n");
    printf("The number of nodes is %d\n", count(t));

    int d;
    printf("Enter the number to be deleted: ");
    scanf("%d", &d);
    delete(&t, d);
    printf("After deletion:\n");
    printf("Preorder: ");
    preorderTraversal(t);
    printf("\n");
    printf("Inorder: ");
    inorderTraversal(t);
    printf("\n");
    printf("Postorder: ");
    postorderTraversal(t);
    printf("\n");
    printf("The number of nodes is %d\n", count(t));

    return 0;
}