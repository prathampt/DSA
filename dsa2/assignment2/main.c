#include "logic.c"

int main()
{
    Tree t;
    init_bst(&t, 4);

    insert_bst(&t, 10);
    insert_bst(&t, 9);
    insert_bst(&t, 8);
    insert_bst(&t, 11);

    for (int i = 0; i < t.size; i++)
    {
        printf("%d ", t.T[i]);
    }

    printf("\n");

    return 0;
}