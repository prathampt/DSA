#include "logic.c"

void menu()
{
    Tree t;
    initBST(&t);

    int MIS, choice;
    char *name = (char *)malloc(sizeof(char) * 50);

    do
    {
        printf("\n----- Binary Search Tree Menu -----\n");
        printf("1. Insert Node\n");
        printf("2. Count Nodes\n");
        printf("3. Remove Node\n");
        printf("4. Search Node\n");
        printf("5. Inorder Traversal\n");
        printf("6. Preorder Traversal\n");
        printf("7. Postorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter MIS number: ");
            scanf("%d", &MIS);
            printf("Enter Name: ");
            scanf("%s", name);
            insertNode(&t, MIS, name);
            printf("Node inserted.\n");
            break;
        case 2:
            printf("Total nodes in the tree: %d\n", count(t));
            break;
        case 3:
            printf("Enter MIS number to remove: ");
            scanf("%d", &MIS);
            removeNode(&t, MIS);
            printf("Node removed.\n");
            break;
        case 4:
            printf("Enter MIS number to search: ");
            scanf("%d", &MIS);
            if (search(t, MIS) == 1)
                printf("Node found.\n");
            else
                printf("Node not found.\n");
            break;
        case 5:
            printf("Inorder Traversal: \n");
            inorderTraversal(t);
            printf("\n");
            break;
        case 6:
            printf("Preorder Traversal: \n");
            preorderTraversal(t);
            printf("\n");
            break;
        case 7:
            printf("Postorder Traversal: \n");
            postorderTraversal(t);
            printf("\n");
            break;
        case 0:
            printf("Exiting DSA 2 assignment 1 program. This is what we call as Binary Search Tree!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main()
{
    menu();
    return 0;
}