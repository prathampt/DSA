#include <stdio.h>
#include "header.h"

void addStudent(Student *s){

    printf("Enter student's Roll number: ");
    scanf("%d", &s->rollNumber);

    printf("Enter first name: ");
    scanf("%s", s->Name.firstName);
    printf("Enter middle name: ");
    scanf("%s", s->Name.middleName);
    printf("Enter last name: ");
    scanf("%s", s->Name.lastName);

    printf("Enter DOB:-\n");
    printf("Day: ");
    scanf("%d", &s->DOB.day);
    printf("Month: ");
    scanf("%d", &s->DOB.month);
    printf("Year: ");
    scanf("%d", &s->DOB.year);

    printf("Enter Marks:-\n");
    printf("English: ");
    scanf("%d", &s->marks[0]);
    printf("Maths: ");
    scanf("%d", &s->marks[1]);
    printf("CS: ");
    scanf("%d", &s->marks[2]);

    return;

}

void displayStudent(Student s){

    printf("Name: %s %s %s\n", s.Name.firstName, s.Name.middleName, s.Name.lastName);
    printf("Roll Number: %d\n", s.rollNumber);
    printf("DOB: %d/%d/%d\n", s.DOB.day, s.DOB.month, s.DOB.year);
    printf("Average marks are: %.2f\n", averageMarksOfStudent(s));
    
    return;
}

float averageMarksOfStudent(Student s){

    float avg = (float) (s.marks[0] + s.marks[1] + s.marks[2]) / 3;
    return avg;
}