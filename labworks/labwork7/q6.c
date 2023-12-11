#include <stdio.h>

// Define the structure for date
typedef struct
{
    int day;
    int month;
    int year;
} Date;

int isValidDate(Date d)
{
    int isLeapYear = ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0));

    if (d.month < 1 || d.month > 12)
    {
        return 0;
    }

    if (d.day < 1)
    {
        return 0;
    }

    switch (d.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return (d.day <= 31);
    case 4:
    case 6:
    case 9:
    case 11:
        return (d.day <= 30);
    case 2:
        return (isLeapYear ? d.day <= 29 : d.day <= 28);
    default:
        return 0; // Invalid month
    }
}

void printDate(Date d)
{
    printf("Date: %02d/%02d/%04d\n", d.day, d.month, d.year);
}

int main()
{

    Date inputDate;

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &inputDate.day, &inputDate.month, &inputDate.year);

    if (isValidDate(inputDate))
    {
        printf("Valid ");
        printDate(inputDate);
    }
    else
    {
        printf("Invalid date entered.\n");
    }

    return 0;
}