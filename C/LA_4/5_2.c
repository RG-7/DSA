/*
    Write a program to implement a stack using
        (b) One Queue.
*/

#include <stdio.h>
#include <stdlib.h>

void enqueue(int *arr, int *front, int *rear, int size, int x)
{
    if ((*rear + 1) % size == *front)
        printf("Queue is Full\n");
    else
    {
        *rear = (*rear + 1) % size;
        arr[*rear] = x;
        if (*front == -1)
            *front = *rear;
    }
}

int dequeue(int *arr, int *front, int *rear, int size)
{
    int x = -1;
    if (*front == -1)
        printf("Queue is Empty\n");
    else
    {
        *front = (*front + 1) % size;
        x = arr[*front];
        if (*front == *rear)
            *front = *rear = -1;
    }
    return x;
}

void push(int *arr, int *front, int *rear, int size, int x)
{
    enqueue(arr, front, rear, size, x);
}

int pop(int *arr, int *front, int *rear, int size)
{
    int x = -1;
    if (size == 0)
    {
        printf("Stack is Empty\n");
    }
    else if (size == 1)
    {
        x = dequeue(arr, front, rear, size);
    }
    else
    {
        int i;
        for (i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[i] = dequeue(arr, front, rear, size);
        size--;
        x = arr[0];
    }
    return x;
}

int main()
{
    int arr[5];
    int front = -1, rear = -1, size = 5;
    push(arr, &front, &rear, size, 4);
    push(arr, &front, &rear, size, 5);
    push(arr, &front, &rear, size, 6);
    printf("Top element is: %d\n", pop(arr, &front, &rear, size));
    printf("Top element is: %d\n", pop(arr, &front, &rear, size));
    return 0;
}