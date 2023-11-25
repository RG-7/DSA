/*
    Develop a menu driven program demonstrating the following operations on Circular Queues:
        (i) enqueue(),
        (ii) dequeue(),
        (iii) isEmpty(),
        (iv) isFull(),
        (v) display(), and
        (vi) peek().
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull()
{
    if ((rear + 1) % MAX == front)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue()
{
    int value = -1;
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        value = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("Removed %d\n", value);
    }
    return value;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        printf("Queue elements: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[i]);
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n***** MENU *****\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. display\n");
        printf("6. peek\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            break;
        case 3:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            value = peek();
            if (value != -1)
            {
                printf("The first element of the queue is %d\n", value);
            }
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}