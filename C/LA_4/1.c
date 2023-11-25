/*
    Develop a menu driven program demonstrating the following operations on simple Queues:
        (i) enqueue(),
        (ii) dequeue(),
        (iii) isEmpty(),
        (iv) isFull(),
        (v) display(), and
        (vi) peek().
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct
{
    int items[SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1);
}

int isFull(Queue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
}

void enqueue(Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = data;
}

int dequeue(Queue *q)
{
    int data = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return data;
    }
    if (q->front == q->rear)
    {
        data = q->items[q->front];
        q->front = -1;
        q->rear = -1;
        return data;
    }
    data = q->items[q->front];
    q->front = (q->front + 1) % SIZE;
    return data;
}

void display(Queue *q)
{
    int i = q->front;
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contains: ");
    for (i = q->front; i != q->rear; i = (i + 1) % SIZE)
    {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]);
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

int main()
{
    Queue q;
    initQueue(&q);
    int choice, data;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. enqueue()\n");
        printf("2. dequeue()\n");
        printf("3. isEmpty()\n");
        printf("4. isFull()\n");
        printf("5. display()\n");
        printf("6. peek()\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
            data = dequeue(&q);
            if (data != -1)
            {
                printf("Dequeued data: %d\n", data);
            }
            break;
        case 3:
            if (isEmpty(&q))
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 4:
            if (isFull(&q))
            {
                printf("Queue is full.\n");
            }
            else
            {
                printf("Queue is not full.\n");
            }
            break;
        case 5:
            display(&q);
            break;
        case 6:
            data = peek(&q);
            if (data != -1)
            {
                printf("Peeked data: %d\n", data);
            }
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}