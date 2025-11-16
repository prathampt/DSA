typedef struct stack
{
    int size, top;
    int *A;
} Stack;

void init(Stack *s, int size);
int isFull(Stack s);
void push(Stack *s, int data);
int isEmpty(Stack s);
int pop(Stack *s);
int peek(Stack s);
void display(Stack s);