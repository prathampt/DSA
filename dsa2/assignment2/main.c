#include "logic.c"

int main()
{
    Tree t;
    init_bst(&t, 31);

    insert_bst(&t, 50);
    insert_bst(&t, 30);
    insert_bst(&t, 70);
    insert_bst(&t, 20);
    insert_bst(&t, 40);
    insert_bst(&t, 60);
    insert_bst(&t, 80);
    insert_bst(&t, 5);
    insert_bst(&t, 25);
    insert_bst(&t, 35);
    insert_bst(&t, 45);
    insert_bst(&t, 55);
    insert_bst(&t, 65);
    insert_bst(&t, 75);
    insert_bst(&t, 85);

    printf("Level-wise Printing:\n");
    levelwise(t);
    printf("\n");
    printf("Inorder Printing: ");
    inorder(t);
    printf("\n");

    printf("The height of the tree is %d\n", height(t));

    printf("Is-Complete: %s\n", isComplete(t) == 1 ? "True" : "False");

    return 0;
}