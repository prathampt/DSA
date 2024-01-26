#include "logic.c"

int main() {
    Stack s;
    init(&s);

    int choice, value;

    do {
        printf("Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                if (!isEmpty(s)) {
                    printf("Popped value: %d\n", pop(&s));
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Let's take a peek at the stack: I saw %d\n", peek(s));
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
