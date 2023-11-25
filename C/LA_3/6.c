/*
    ADDITIONAL QUESTION 1
    Given an array A, find the nearest smaller element for every element A[i] in the array such that the element has an index smaller than i.
*/

#include <stdio.h>
#include <stdlib.h>

// Stack type definition
typedef struct
{
    int top;
    int capacity;
    int *array;
} Stack;

// Function to create a stack of given capacity.
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    if (!stack->array)
        return NULL;

    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an item to stack.
// It changes top index of stack to point to newly added item.
void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;

    stack->array[++stack->top] = item;
}

// Function to pop an item from stack.
// It changes top index of stack to remove an item.
int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;

    return stack->array[stack->top--];
}

// Function to find the nearest smaller element to the left of a given element
void nearestSmallerToLeft(int arr[], int n)
{
    Stack *stack = createStack(n);

    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && arr[i] < arr[stack->top])
        {
            arr[stack->top] = -1;
            pop(stack);
        }

        if (!isEmpty(stack))
            arr[i] = stack->array[stack->top];

        push(stack, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {10, 8, 2, 1, 7, 3, 2, 1, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    nearestSmallerToLeft(arr, n);

    return 0;
}