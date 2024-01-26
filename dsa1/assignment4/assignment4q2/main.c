#include <stdio.h>
#include "logic.c"

int main(){
    Student students[5];

    printf("Enter information of five students:\n");

    for (int i = 0; i < 5; i++)
    {
        addStudent(&students[i]);
    }

    printf("Displaying the information of students you have entered:\n");
    
    for (int i = 0; i < 5; i++)
    {
        displayStudent(students[i]);
    }

    return 0;
}