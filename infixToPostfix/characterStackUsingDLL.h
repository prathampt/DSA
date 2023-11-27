typedef struct node{
    char data;
    struct node * next, * previous;
}Node;

typedef struct stack{
    Node *base, *top;
}Stack;

void init(Stack *s);
int isEmpty(Stack s);
void push(Stack *s, char data);
char pop(Stack *s);
char peek(Stack s);
void display(Stack s);