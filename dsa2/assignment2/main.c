#include "logic.c"

int main()
{
    Tree t;
    init_bst(&t, 7);

    insert_bst(&t, 60);
    insert_bst(&t, 50);
    insert_bst(&t, 65);
    insert_bst(&t, 45);
    insert_bst(&t, 55);
    insert_bst(&t, 63);
    insert_bst(&t, 70);

    printf("Level-wise Printing: ");
    levelwise(t);
    printf("\n");
    printf("Inorder Printing: ");
    inorder(t);
    printf("\n");

    return 0;
}