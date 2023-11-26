typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct queue{
    Node * front;
    Node * rear;
}Queue;

void init(Queue *q);
void enQueue(Queue *q, int data);
int deQueue(Queue *q);
int isEmpty(Queue q);
int peek(Queue q);
void display(Queue q);
