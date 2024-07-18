// Stack operations

#include <stdio.h>
#include <stdlib.h>

int *stack, max, top = -1;

void push(int ele)
{
    if (top == max - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = ele;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
        return (stack[top--]);
}

void display()
{
    int i;
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
    }
}

void palindrome()
{
    int n, rev, rem, ncopy;
    printf("Enter the value of the n:\n");
    scanf("%d", &n);
    ncopy = n;
    top = -1;
    while (n != 0)
    {
        rem = n % 10;
        push(rem);
        n = n / 10;
    }
    while (ncopy != 0)
    {
        rem = ncopy % 10;
        if (rem != pop())
        {
            printf("Given number is not a palindrome");
            top = -1;
            return;
        }
        ncopy = ncopy / 10;
    }
    printf("It is a palindrome");
}

int main()
{
    int choice, ele;
    printf("Enter the size of stack:\n");
    scanf("%d", &max);
    stack = (int *)malloc(max * sizeof(int));
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1: Push\n2: Pop\n3: Display\n4: Palindrome\n5: Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            ele = pop();
            if (ele != -1)
                printf("Deleted element is %d\n", ele);
            break;
        case 3:
            display();
            break;
        case 4:
            palindrome();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input");
        }
    }
}