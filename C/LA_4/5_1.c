/*
    Write a program to implement a stack using
        (a) Two queues
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
typedef struct
{
    int data;
} QueueNode;

// Structure to represent a queue
typedef struct
{
    QueueNode items[100];
    int front;
    int rear;
} Queue;

// Function to initialize an empty queue
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return (q->front == -1) && (q->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue *q)
{
    return (q->rear + 1) % 100 == q->front;
}

// Function to enqueue an element
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full, cannot enqueue.\n");
    }
    else
    {
        if (isEmpty(q))
        {
            q->front = q->rear = 0;
        }
        else
        {
            q->rear = (q->rear + 1) % 100;
        }
        q->items[q->rear].data = value;
    }
}

// Function to dequeue an element
int dequeue(Queue *q)
{
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty, cannot dequeue.\n");
    }
    else
    {
        value = q->items[q->front].data;
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % 100;
        }
    }
    return value;
}

// Structure to represent a stack using two queues
typedef struct
{
    Queue q1;
    Queue q2;
} StackUsingTwoQueues;

// Function to initialize a stack using two queues
void initStackUsingTwoQueues(StackUsingTwoQueues *stack)
{
    initQueue(&stack->q1);
    initQueue(&stack->q2);
}

// Function to push an element onto the stack
void pushStackUsingTwoQueues(StackUsingTwoQueues *stack, int value)
{
    // Enqueue the element to q1
    enqueue(&stack->q1, value);
}

// Function to pop an element from the stack
int popStackUsingTwoQueues(StackUsingTwoQueues *stack)
{
    int poppedValue = -1;

    if (!isEmpty(&stack->q1))
    {
        // Dequeue all elements from q1 to q2 except the last one
        while (stack->q1.front != stack->q1.rear)
        {
            enqueue(&stack->q2, dequeue(&stack->q1));
        }

        // Dequeue the last element from q1
        poppedValue = dequeue(&stack->q1);

        // Swap q1 and q2
        Queue temp = stack->q1;
        stack->q1 = stack->q2;
        stack->q2 = temp;
    }

    return poppedValue;
}

int main()
{
    StackUsingTwoQueues stack;
    initStackUsingTwoQueues(&stack);

    // Sample operations
    pushStackUsingTwoQueues(&stack, 1);
    pushStackUsingTwoQueues(&stack, 2);
    pushStackUsingTwoQueues(&stack, 3);

    printf("Popped: %d\n", popStackUsingTwoQueues(&stack));
    printf("Popped: %d\n", popStackUsingTwoQueues(&stack));

    return 0;
}
