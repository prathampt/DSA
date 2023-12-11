/*
Question: Write a C program to input electricity unit charges and calculate the total electricity bill according to the given condition:
For the first 50 units Rs. 0.50/unit
For the next 100 units Rs. 0.75/unit
For the next 100 units Rs. 1.20/unit
For units above 250 Rs. 1.50/unit
An additional surcharge of 20% is added to the bill
*/

#include <stdio.h>

int main() {
    int units;
    float totalBill, surcharge;

    // Input electricity unit charges
    printf("Enter the electricity unit charges: ");
    scanf("%d", &units);

    // Calculate total bill based on the given conditions
    if (units <= 50) {
        totalBill = units * 0.50;
    } else if (units <= 150) {
        totalBill = 50 * 0.50 + (units - 50) * 0.75;
    } else if (units <= 250) {
        totalBill = 50 * 0.50 + 100 * 0.75 + (units - 150) * 1.20;
    } else {
        totalBill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (units - 250) * 1.50;
    }

    // Calculate surcharge
    surcharge = 0.2 * totalBill;

    // Add surcharge to the total bill
    totalBill += surcharge;

    // Print the total electricity bill
    printf("Total Electricity Bill: Rs. %.2f\n", totalBill);

    return 0;
}
