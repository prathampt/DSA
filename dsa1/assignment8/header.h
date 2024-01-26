typedef struct node{
    char data;
    struct node * next;
}Node;

typedef struct queue{
    Node * front;
    Node * rear;
}Queue;

void init(Queue *q);
void enQueue(Queue *q, char data);
char deQueue(Queue *q);
int isEmpty(Queue q);
char peek(Queue q);
void display(Queue q);
