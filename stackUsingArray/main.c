#include "logic.c"

int main(){
    Stack s;

    init(&s, 6);

    push(&s, 4);
    push(&s, 3);
    push(&s, -40);

    display(s);

    push(&s, -34);
    push(&s, 0);

    display(s);

    printf("%d\n", s.top);

    printf("Pop: %d\n", pop(&s));

    printf("%d\n", s.top);

    display(s);

    printf("Let's take a peek on to the stack: I saw %d\n", peek(s));

    return 0;

}