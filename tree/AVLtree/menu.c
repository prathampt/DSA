#include "logic.c"

void menu() {
    printf("\n---------------------AVL Tree Menu----------------------\n");
    printf("1. Initialize AVL Tree\n");
    printf("2. Insert a Node\n");
    printf("3. Remove a Node\n");
    printf("4. Traverse AVL Tree\n");
    printf("5. Destroy AVL Tree\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    AVLtree  T;
    char *name = (char *)malloc(sizeof(char) * 50);
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                init(&T);
                break;
            case 2:
                printf("Enter Name: ");
                scanf("%s", name);
                insertNode(&T, name);
                printf("Node inserted.\n");
                break;
            case 3:
                printf("Enter Name: ");
                scanf("%s", name);
                removeNode(&T, name);
                printf("Node Deleted.\n");
                break;
            case 4:
                printf("Inorder Traversal of the Tree: \n");
                traverse(T);
                break;
            case 5:
                destroyTree(&T);
                printf("AVL Tree destroyed.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 6);

    return 0;
}