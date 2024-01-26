typedef struct {
    int rollNumber;

    struct {
        char firstName[20];
        char middleName[20];
        char lastName[20]; 
    } Name;

    struct {
        int day;
        int month;
        int year;
    } DOB;    

    int marks[3];
    
} Student;

void addStudent(Student *s);
void displayStudent(Student s);
float averageMarksOfStudent(Student s);
