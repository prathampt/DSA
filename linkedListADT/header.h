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
int removeNode(List *l, Node *n);
void addNodeAtPosition(List *l, int data, int position);
int length(List l);
void swapNodes(List * l, Node * n1, Node * n2);
void fill(List *l, int number);
void reverseEven(List *l);
int isPalindrome(List l);
void removeDuplicates(List *l);
void destroy(List *l);
void removeAndInsert(List *l, Node *n, int index);