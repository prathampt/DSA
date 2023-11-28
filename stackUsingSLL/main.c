#include "logic.c"

int main(){
    Stack s;

    init(&s);

    push(&s, 6);
    push(&s, 7);
    push(&s, -5);
    push(&s, 0);
    push(&s, -2);
    push(&s, 1);

    display(s);

    push(&s, -65);
    push(&s, 48);

    display(s);

    pop(&s);
    pop(&s);
    pop(&s);

    display(s);

    printf("Let's take a peek on to the stack: I saw %d\n", peek(s));

    return 0;
}