/*
    Develop a menu driven program demonstrating the following operations on a Stack using array:
        (i) push(),
        (ii) pop(),
        (iii) isEmpty(),
        (iv) isFull(),
        (v) display(), and
        (vi) peek().
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top = -1;
int stack[MAX];

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int val)
{
    if (isFull())
    {
        printf("Stack is Full. Cannot push %d into stack.\n", val);
    }
    else
    {
        top++;
        stack[top] = val;
        printf("%d pushed into stack.\n", val);
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty. Cannot pop an element from stack.\n");
        return -1;
    }
    else
    {
        int popped = stack[top];
        top--;
        printf("%d popped from stack.\n", popped);
        return popped;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty. Cannot peek an element from stack.\n");
    }
    else
    {
        printf("Top element of stack is %d.\n", stack[top]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is Empty. Cannot display elements of stack.\n");
    }
    else
    {
        printf("Elements of stack are:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\n\n******MENU******\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty?\n");
        printf("4. Is Full?\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("7. Exit\n");
        printf("*****************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack is Empty.\n");
            }
            else
            {
                printf("Stack is not Empty.\n");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("Stack is Full.\n");
            }
            else
            {
                printf("Stack is not Full.\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 7);
    return 0;
}