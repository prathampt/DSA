#include "logic.c"

int main(){
    Queue q;
    init(&q);

    for (int i = 0; i < 10; i++)
    {
        enQueue(&q, rand() % 100 + 1);
    }

    display(q);

    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);

    display(q);

    printf("Let's take a peek: %d\n", peek(q));

    enQueue(&q, 56);
    for (int i = 0; i < 7; i++)
    {
        enQueue(&q, rand() % 100 + 1);
    }
    display(q);
    
    return 0;  
}