typedef struct node{
    int data;
    struct node * next, * previous;
}Node;

typedef struct stack{
    Node *base, *top;
}Stack;

void init(Stack *s);
int isEmpty(Stack s);
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack s);
void display(Stack s);