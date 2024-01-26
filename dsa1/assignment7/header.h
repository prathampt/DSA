typedef struct node{
    int data;
    struct node * next;
} Node;

typedef Node * Stack;

void init(Stack *s);
int isEmpty(Stack s);
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack s);
void display(Stack s);