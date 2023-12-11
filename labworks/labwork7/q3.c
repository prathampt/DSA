#include <stdio.h>

typedef struct {
    char name[50];
    char address[100];
    int grade;
    int numRooms;
    float roomCharges;
} Hotel;

void grade(Hotel hotels[], int numHotels, int targetGrade) {
    printf("Hotels in Grade %d:\n", targetGrade);
    for (int i = 0; i < numHotels; ++i) {
        if (hotels[i].grade == targetGrade) {
            printf("%s\n", hotels[i].name);
        }
    }
}

void lessThanCharge(Hotel hotels[], int numHotels, float maxRoomCharge) {
    printf("\nHotels with Room Charges Less Than %.2f:\n", maxRoomCharge);
    for (int i = 0; i < numHotels; ++i) {
        if (hotels[i].roomCharges < maxRoomCharge) {
            printf("%s\n", hotels[i].name);
        }
    }
}

int main() {
    const int numHotels = 3; 
    Hotel hotels[numHotels];


    for (int i = 0; i < numHotels; ++i) {
        printf("Enter details for hotel %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", hotels[i].name);
        printf("Address: ");
        scanf("%s", hotels[i].address);
        printf("Grade: ");
        scanf("%d", &hotels[i].grade);
        printf("Number of Rooms: ");
        scanf("%d", &hotels[i].numRooms);
        printf("Room Charges: ");
        scanf("%f", &hotels[i].roomCharges);// Define the structure for a hotel

        printf("\n");
    }

    int targetGrade;
    printf("Enter the grade to search for hotels: ");
    scanf("%d", &targetGrade);
    grade(hotels, numHotels, targetGrade);

    float maxRoomCharge;
    printf("Enter the maximum room charge: ");
    scanf("%f", &maxRoomCharge);
    lessThanCharge(hotels, numHotels, maxRoomCharge);

    return 0;
}
