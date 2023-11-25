/*
    Write a program to find size of
        i. Doubly Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the Doubly Linked List
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

// Function to find the size of the Doubly Linked List
int findSizeDoublyLinkedList(struct Node *head)
{
    int size = 0;
    struct Node *current = head;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}

// Function to free the memory allocated for the Doubly Linked List
void freeDoublyList(struct Node *head)
{
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter the number of elements in the Doubly Linked List: ");
    scanf("%d", &n);

    printf("Enter the elements of the Doubly Linked List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    int size = findSizeDoublyLinkedList(head);
    printf("Size of the Doubly Linked List: %d\n", size);

    // Free allocated memory
    freeDoublyList(head);

    return 0;
}
