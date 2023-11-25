/*
    ADDITIONAL QUESTION 2
    Design a stack that supports getMin() in O(1) time and O(1) extra space.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int min;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (stack->top == NULL)
    {
        newNode->min = data;
    }
    else
    {
        newNode->min = (data < stack->top->min) ? data : stack->top->min;
    }

    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    int popped = stack->top->data;
    stack->top = stack->top->next;
    return popped;
}

int peek(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->top->data;
}

int getMin(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->top->min;
}

int main()
{
    Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 15);
    printf("Min: %d\n", getMin(stack));
    pop(stack);
    printf("Min: %d\n", getMin(stack));
    return 0;
}