/*
    ADDITIONAL QUESTION 3
    Program for Page Replacement Algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the queue
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure to represent a queue
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// Function to initialize an empty queue
void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q)
{
    return q->front == NULL;
}

// Function to enqueue a page into the queue
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a page from the queue
int dequeue(Queue *q)
{
    int value = -1;
    if (!isEmpty(q))
    {
        Node *temp = q->front;
        value = temp->data;

        q->front = temp->next;
        free(temp);

        if (q->front == NULL)
        {
            q->rear = NULL;
        }
    }
    return value;
}

// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity)
{
    Queue q;
    initQueue(&q);

    // To represent set of current pages.
    bool *s = (bool *)calloc(capacity, sizeof(bool));

    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (!s[pages[i]])
        {
            // Insert it into the set if not present already
            // which represents a page fault
            s[pages[i]] = true;

            // Increment page fault
            page_faults++;

            // Push the current page into the queue
            enqueue(&q, pages[i]);

            // If the set is full, perform FIFO
            if (q.front && q.rear && q.rear->next)
            {
                int val = dequeue(&q);

                // Remove the oldest page from the set
                s[val] = false;
            }
        }
    }

    free(s);
    return page_faults;
}

// Driver code
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    printf("%d\n", pageFaults(pages, n, capacity));
    return 0;
}
