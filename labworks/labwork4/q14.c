/*
Question: Write a C program to input marks of five subjects Physics, Chemistry, Biology, Mathematics, and Computer. Calculate percentage and grade according to the following:
Percentage >= 90% : Grade A
Percentage >= 80% : Grade B
Percentage >= 70% : Grade C
Percentage >= 60% : Grade D
Percentage >= 40% : Grade E
Percentage < 40% : Grade F
*/

#include <stdio.h>

int main() {
    float physics, chemistry, biology, mathematics, computer;
    float totalMarks, percentage;

    // Input marks for each subject
    printf("Enter marks for Physics: ");
    scanf("%f", &physics);

    printf("Enter marks for Chemistry: ");
    scanf("%f", &chemistry);

    printf("Enter marks for Biology: ");  
    scanf("%f", &biology);

    printf("Enter marks for Mathematics: ");
    scanf("%f", &mathematics);

    printf("Enter marks for Computer: ");
    scanf("%f", &computer);

    // Calculate total marks and percentage
    totalMarks = physics + chemistry + biology + mathematics + computer;
    percentage = (totalMarks / 500) * 100;

    // Determine and print the grade based on the percentage
    printf("Percentage: %.2f%%\n", percentage);
    if (percentage >= 90)
        printf("Grade: A\n");
    else if (percentage >= 80)
        printf("Grade: B\n");
    else if (percentage >= 70)
        printf("Grade: C\n");
    else if (percentage >= 60)
        printf("Grade: D\n");
    else if (percentage >= 40)
        printf("Grade: E\n");
    else
        printf("Grade: F\n");

    return 0;
}
