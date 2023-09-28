#include <stdio.h>
#include "logic.c"

int main() {
    Distance distance1, distance2, result;
    int choice;

    do {
        printf("******** MAIN MENU *********\n");
        printf("1. Read the distances\n");
        printf("2. Display the distances\n");
        printf("3. Add the distances\n");
        printf("4. Subtract the distances\n");
        printf("5. EXIT\n");
        printf("****************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first distance:\n");
                readDistance(&distance1);
                printf("Enter the second distance:\n");
                readDistance(&distance2);
                break;
            case 2:
                printf("First distance: ");
                displayDistance(distance1);
                printf("Second distance: ");
                displayDistance(distance2);
                break;
            case 3:
                result = addDistances(distance1, distance2);
                printf("Sum of distances is: ");
                displayDistance(result);
                break;
            case 4:
                result = subtractDistances(distance1, distance2);
                printf("Subtraction of distances is: ");
                displayDistance(result);
                break;
            case 5:
                printf("Exiting the program. Goodbye!!! See you in the next program!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("****************************\n");

    } while (choice != 5);

    return 0;
}
