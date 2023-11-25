/*
    Write a program interleave the first half of the queue with second half.
        Sample I/P:
            4 7 11 20 5 9
        Sample O/P:
            4 20 7 5 11 9
*/

#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct
{
    int items[MAX_SIZE];
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
    return (q->rear + 1) % MAX_SIZE == q->front;
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
            q->rear = (q->rear + 1) % MAX_SIZE;
        }
        q->items[q->rear] = value;
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
        value = q->items[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % MAX_SIZE;
        }
    }
    return value;
}

// Function to interleave the first half of the queue with the second half
void interleave(Queue *q)
{
    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE + 1;

    if (size % 2 != 0)
    {
        // For odd-sized queue, reduce the size by 1 to make it even
        size--;
    }

    int halfSize = size / 2;

    int tempQueue[MAX_SIZE];
    int tempFront = 0, tempRear = -1;

    // Dequeue the first half and enqueue into temporary queue
    for (int i = 0; i < halfSize; ++i)
    {
        int value = dequeue(q);
        tempRear = (tempRear + 1) % MAX_SIZE;
        tempQueue[tempRear] = value;
    }

    // Interleave the elements and enqueue back into the original queue
    for (int i = 0; i < halfSize; ++i)
    {
        enqueue(q, tempQueue[i]);
        enqueue(q, dequeue(q));
    }
}

// Function to display the elements of the queue
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = q->front;
        do
        {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (q->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main()
{
    Queue q;
    initQueue(&q);

    // Sample input
    enqueue(&q, 4);
    enqueue(&q, 7);
    enqueue(&q, 11);
    enqueue(&q, 20);
    enqueue(&q, 5);
    enqueue(&q, 9);

    printf("Original Queue:\n");
    display(&q);

    // Interleave the first half with the second half
    interleave(&q);

    printf("\nInterleaved Queue:\n");
    display(&q);

    return 0;
}
