typedef struct node
{
    int data;
    struct node * next;
}Node;

typedef Node * List;

void init(List *l);
void display(List l);

void append(List *l, int data);
void insertAtBeginning(List *l, int data);

int removeEnd(List *l);
int removeBeginning(List *l);

int length(List l);
void fill(List *l, int number);
void destroy(List *l);