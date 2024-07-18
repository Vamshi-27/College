// Infix to postfix conversion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ele)
{
    stack[++top] = ele;
}

char pop()
{
    return stack[top--];
}

int prec(char sym)
{
    switch (sym)
    {
    case '^':
    case '$':
        return 4;
    case '%':
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
    case ')':
    case '#':
        return 1;
    default:
        return 0;
    }
}

void convertip(char infix[], char postfix[]) {
    char symbol;
    int i = 0;
    int j = 0;
    push('#');
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
        case '(':
            push(symbol);
            break;
        case ')':
            while (stack[top] != 'c')
                postfix[j++] = pop();
            pop();
            break;
        case '^':
        case '$':
        case '%':
        case '/':
        case '*':
        case '+':
        case '-':
            while (prec(symbol) <= prec(stack[top])) {
                postfix[j++] = pop();
                push(symbol);
            }
            break;
        default:
            postfix[j++] = symbol;
            while (stack[top] != '#')
                postfix[j++] = pop();
            postfix[j++] = '\0';
        }
    }
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression:\n");
    gets(infix);
    convertip(infix, postfix);
    printf("The postfix expression is:\n%s\n", postfix);
    return 0;
}