#include "logic.c"

int main(){
    AVLtree  T;
    init(&T);

    insertNode(&T, "Pratham");
    insertNode(&T, "Bhavya");
    insertNode(&T, "Anjali");
    insertNode(&T, "Vaishanavi");
    insertNode(&T, "Vaishnavi");
    insertNode(&T, "Rohit");
    insertNode(&T, "Prajakta");

    printf("Tree:\n");
    traverse(T);

    removeNode(&T, "Vaishnavi");
    removeNode(&T, "Pratham");

    printf("Tree:\n");
    traverse(T);
    
    insertNode( &T,"Akash");
    printf("Tree:\n");
    traverse(T);

    destroyTree(&T);

    printf("Tree:\n");
    traverse(T); // This should print an empty tree since the tree has been destroyed...

    return 0;
}