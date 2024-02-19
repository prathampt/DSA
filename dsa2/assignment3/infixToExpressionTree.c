#include "binaryTree.c"
#include <limits.h>
#include <ctype.h>
#include <string.h>

int operatorPrecedence(char c)
{
    switch (c)
    {
    case '(':
        return INT_MIN;
    case '-':
    case '+':
        return 0;
    case '*':
    case '/':
    case '%':
        return 1;
    case '^':
        return 2;
    }
}

int isOperator(char c)
{
    switch (c)
    {
    case '-':
    case '+':
    case '*':
    case '/':
    case '%':
    case '^':
        return 1;
    default:
        return 0;
    }
}

void expressionTree(Tree *T, char *infix)
{
    Stack operandStack, operatorStack;
    Sinit(&operandStack);
    Sinit(&operatorStack);
    int i = 0, j = 0, operator= 0;
    char c;
    char *operand = (char *)malloc(sizeof(char) * strlen(infix));

    while ((c = infix[i]) != '\0')
    {
        if (c == ' ' && operator== 0)
        {
            if (j == 0){
                i++;
                continue;
            }
            operand[j++] = '\0';
            i++;
            push(&operandStack, generateNode(operand));
            free(operand);
            operand = (char *)malloc(sizeof(char) * strlen(infix));
            j = 0;
            continue;
        }

        if (c == ' ')
        {
            i++;
            continue;
        }

        if (infix[i] == '+' && i == 0)
        {
            i++;
            continue;
        }

        if (infix[i] == '-' && i == 0)
        {
            operand[j++] = infix[i++];
            continue;
        }

        if (c == '(')
        {
            char * z = (char *)malloc(sizeof(char) * 2);
            z[0] = c, z[1] = '\0';

            push(&operatorStack, generateNode(z));
            i++;
            operator= 1;
            continue;
        }

        if (c == ')')
        {
            if (j != 0){
                operand[j++] = '\0';
                push(&operandStack, generateNode(operand));
                free(operand);
                operand = (char *)malloc(sizeof(char) * strlen(infix));
                j = 0;
            }
            
            Node *t = peek(operatorStack);
            while (*t->s != '(')
            {
                t = pop(&operatorStack);
                t->right = pop(&operandStack);
                t->left = pop(&operandStack);
                push(&operandStack, t);
                t = peek(operatorStack);
            }
            operator= 0;
            i++;
            pop(&operatorStack);
            continue;
        }

        if (isOperator(c))
        {

            if (operator)
            {
                if (c == '-')
                {
                    operand[j++] = c;
                    i++;
                    continue;
                }
                else if (c == '+')
                {
                    i++;
                    continue;
                }
                else
                {
                    printf("Invalid Infix Expression!\n");
                    return;
                }
            }

            if (isEmpty(operatorStack))
            {
                char * z = (char *)malloc(sizeof(char) * 2);
                z[0] = c, z[1] = '\0';
                push(&operatorStack, generateNode(z));
                operator= 1;
                i++;
                continue;
            }
            Node *p = peek(operatorStack);
            while (operatorPrecedence(*p->s) >= operatorPrecedence(c))
            {
                p = pop(&operatorStack);
                p->right = pop(&operandStack);
                p->left = pop(&operandStack);
                push(&operandStack, p);
                if (isEmpty(operatorStack))
                    break;
                p = peek(operatorStack);
            }
            char * z = (char *)malloc(sizeof(char) * 2);
            z[0] = c, z[1] = '\0';
            push(&operatorStack, generateNode(z));
            operator= 1;
            i++;
            continue;
        }

        operand[j++] = c;
        operator= 0;
        i++;
    }
    if (j != 0){
        operand[j++] = '\0';
        push(&operandStack, generateNode(operand));
    }
    
    Node *t = NULL;
    while (!isEmpty(operatorStack))
    {
        t = pop(&operatorStack);
        t->right = pop(&operandStack);
        t->left = pop(&operandStack);
        push(&operandStack, t);
    }

    *T = pop(&operandStack);
    return;
}