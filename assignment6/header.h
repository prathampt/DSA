typedef struct node{
    int row, col, val;
    struct node * next;
}Node;

typedef struct sparse{
    int row, col;
    Node * header;
}Sparse;

void init(Sparse *s);
void append(Sparse *s, int row, int col, int val);
void display(Sparse s);
Sparse * add(Sparse s1, Sparse s2);
Sparse * subtract(Sparse s1, Sparse s2);
void readFromFile(char *fileName, Sparse *s);
void writeIntoFile(char *fileName, Sparse s);
