typedef struct qnode{
    char data;
    struct qnode * next;
} qNode;

typedef struct queue{
    qNode * front;
    qNode * rear;
} Queue;

void initQ(Queue *q);
void enQueue(Queue *q, char data);
char deQueue(Queue *q);
int isEmpty(Queue q);
char peek(Queue q);
void displayQueue(Queue q);
