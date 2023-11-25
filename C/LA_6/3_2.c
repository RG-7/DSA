/*
    Write a program to find size of
        ii. Circular Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the Circular Linked List
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // Point to itself in a circular list
    }
    else
    {
        struct Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }

    return head;
}

// Function to find the size of the Circular Linked List
int findSizeCircularLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int size = 0;
    struct Node *current = head;

    do
    {
        size++;
        current = current->next;
    } while (current != head);

    return size;
}

// Function to free the memory allocated for the Circular Linked List
void freeCircularList(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Node *current = head;
    struct Node *nextNode;

    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter the number of elements in the Circular Linked List: ");
    scanf("%d", &n);

    printf("Enter the elements of the Circular Linked List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    int size = findSizeCircularLinkedList(head);
    printf("Size of the Circular Linked List: %d\n", size);

    // Free allocated memory
    freeCircularList(head);

    return 0;
}
