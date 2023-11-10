typedef struct node {
    int data;
    struct node *next, *previous;
} Node;

typedef struct list {
    Node * front, * rear;
} List;

void init(List *l);

void append(List *l, int data);
void insertAtBeginning(List *l, int data);
void insertAtIndex(List *l, int data, int index);

int removeEnd(List *l);
int removeBeginning(List *l);
int removeAtIndex(List *l, int index);
int removeNode(List *l, Node * n);

void display(List l);
int length(List l);

void fill(List *l, int numberOfNodes);
void swapNodes(List *l, Node *n1, Node *n2);