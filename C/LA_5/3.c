/*
    Write a program to find the middle of a linked list.
        Input:
            1->2->3->4->5
        Output:
            3
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
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

// Function to insert a node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to find the middle of the linked list
struct Node *findMiddle(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    // Traverse the list with two pointers, one moving at twice the speed of the other
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to display all node values in the linked list
void display(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node *head)
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

    // Example: Creating a linked list with given values
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Display the original linked list
    printf("Original Linked List: ");
    display(head);

    // Find the middle of the linked list
    struct Node *middle = findMiddle(head);

    // Display the middle element
    if (middle != NULL)
    {
        printf("Middle Element: %d\n", middle->data);
    }
    else
    {
        printf("List is empty.\n");
    }

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
