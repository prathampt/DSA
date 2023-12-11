#include <stdio.h>
#include <string.h>

typedef struct
{
    int d, m, y;
} D;

typedef struct
{
    float e, m, c;
} M;

typedef struct
{
    char f[50], m[50], l[50];
} Name;

typedef struct
{
    Name n;
    int r;
    char g;
    D dob;
    M mks;
} Student;

float avg(M marks)
{
    return (marks.e + marks.m + marks.c) / 3.0;
}

int main()
{
    Student s;
    s.r = 101;
    s.n = (Name){"Bhavya", "Anand", "Shah"};
    s.g = 'M';
    s.dob = (D){15, 5, 2000};
    s.mks = (M){77.5, 90.0, 88.5};

    printf("Roll Number: %d\n", s.r);
    printf("Name: %s %s %s\n", s.n.f, s.n.m, s.n.l);
    printf("Gender: %c\n", s.g);
    printf("Date of Birth: %d/%d/%d\n", s.dob.d, s.dob.m, s.dob.y);
    printf("Marks - English: %.2f, Mathematics: %.2f, Computer Science: %.2f\n", s.mks.e, s.mks.m, s.mks.c);
    char srchFame[50];
    printf("\nEnter the first name of the student to display details: ");
    scanf("%s", srchFame);

    if (strcmp(srchFame, s.n.f) == 0)
    {
        printf("\nDetails of student with first name %s:\n", srchFame);
        printf("Roll Number: %d\n", s.r);
        printf("Name: %s %s %s\n", s.n.f, s.n.m, s.n.l);
        printf("Gender: %c\n", s.g);
        printf("Date of Birth: %d/%d/%d\n", s.dob.d, s.dob.m, s.dob.y);
        printf("Marks - English: %.2f, Mathematics: %.2f, Computer Science: %.2f\n", s.mks.e, s.mks.m, s.mks.c);
    }
    else
    {
        printf("Student with the given first name not found.\n");
    }
    float aggregate = avg(s.mks);
    if (aggregate < 40.0)
    {
        printf("\n%s %s %s has secured less than 40%% aggregate. Average Marks: %.2f\n", s.n.f, s.n.m, s.n.l, aggregate);
    }
    else
    {
        printf("\n%s %s %s has secured 40%% or more aggregate. Average Marks: %.2f\n", s.n.f, s.n.m, s.n.l, aggregate);
    }

    return 0;
}
