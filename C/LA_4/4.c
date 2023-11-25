/*
    Write a program to find first non-repeating character in a string using Queue.
        Sample I/P:
            a a b c
        Sample O/P:
            a -1 b b
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a queue node
typedef struct
{
    char data;
    int count;
} QueueNode;

// Structure to represent a queue
typedef struct
{
    QueueNode items[MAX_SIZE];
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

// Function to enqueue a character with its count
void enqueue(Queue *q, char value, int count)
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
        q->items[q->rear].data = value;
        q->items[q->rear].count = count;
    }
}

// Function to dequeue a character with its count
QueueNode dequeue(Queue *q)
{
    QueueNode node;
    node.data = '\0';
    node.count = -1;

    if (isEmpty(q))
    {
        printf("Queue is empty, cannot dequeue.\n");
    }
    else
    {
        node = q->items[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % MAX_SIZE;
        }
    }
    return node;
}

// Function to find the first non-repeating character in the string
void findFirstNonRepeating(char *str)
{
    int charCount[256] = {0}; // Assuming ASCII characters

    Queue q;
    initQueue(&q);

    int len = strlen(str);

    for (int i = 0; i < len; ++i)
    {
        char currentChar = str[i];
        charCount[currentChar]++;
        enqueue(&q, currentChar, charCount[currentChar]);
    }

    while (!isEmpty(&q))
    {
        QueueNode node = dequeue(&q);

        if (node.count == 1)
        {
            printf("%c ", node.data);
        }
        else
        {
            printf("-1 ");
        }
    }

    printf("\n");
}

int main()
{
    char inputString[100];

    // Sample input
    printf("Enter a string: ");
    scanf("%s", inputString);

    printf("Output:\n");
    findFirstNonRepeating(inputString);

    return 0;
}
