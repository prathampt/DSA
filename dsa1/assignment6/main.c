#include "List.c"

int main(){
    Sparse s1, s2;

    init(&s1);
    init(&s2);

    /*
    readFromFile("matrix1.txt", &s1);
    display(s1);

    readFromFile("matrix2.txt", &s2);
    display(s2);

    Sparse * s3 = add(s1, s2);
    display(*s3);
    writeIntoFile("matrix3.txt", *s3);

    Sparse * s4 = subtract(s1, s2);
    display(*s4);
    writeIntoFile("matrix4.txt", *s4);
    */
    
    readFromFile("Matrix_1.txt", &s1);
    display(s1);

    readFromFile("Matrix_2.txt", &s2);
    display(s2);

    Sparse * s3 = add(s1, s2);
    display(*s3);
    writeIntoFile("MatrixSum.txt", *s3);

    Sparse * s4 = subtract(s1, s2);
    display(*s4);
    writeIntoFile("MatrixDiff.txt", *s4);

    return 0;
}