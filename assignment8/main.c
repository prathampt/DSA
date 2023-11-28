#include "logic.c"

int main() {
    Queue q;
    init(&q);

    int choice;
    char value;

    do {
        printf("Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf(" %c", &value);
                enQueue(&q, value);
                break;
            case 2:
                if (!isEmpty(q)) {
                    printf("Dequeued value: %c\n", deQueue(&q));
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Let's take a peek at the stack: I saw %c\n", peek(q));
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
