#include <stdio.h>
#include "logic.c"

int main(){
    Tree t;
    init(&t);

    insert(&t, 4);
    insert(&t, 2);
    insert(&t, 6);
    insert(&t, 1);
    insert(&t, 3);
    insert(&t, 5);
    insert(&t, 7);

    preorderTraversal(t);
    printf("\n");
    inorderTraversal(t);
    printf("\n");
    postorderTraversal(t);
    printf("\n");
    return 0;
}