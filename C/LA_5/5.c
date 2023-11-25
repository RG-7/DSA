/*
    ADDITIONAL QUESTION 1
    Reverse a linked list from position m to n. Do it in-place and in one-pass.
    For example:
        Given
            1->2->3->4->5->NULL, m = 2 and n = 4,
        return
            1->4->3->2->5->NULL.
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

// Function to reverse a portion of the linked list from position m to n
struct Node *reverseBetween(struct Node *head, int m, int n)
{
    if (head == NULL || m == n)
    {
        return head;
    }

    struct Node *dummy = createNode(0);
    dummy->next = head;
    struct Node *prev = dummy;

    // Move to the starting position (m-1) in the linked list
    for (int i = 0; i < m - 1; ++i)
    {
        prev = prev->next;
    }

    // Reverse the portion from position m to n
    struct Node *current = prev->next;
    struct Node *nextNode = NULL;

    for (int i = 0; i < n - m + 1; ++i)
    {
        struct Node *temp = current->next;
        current->next = nextNode;
        nextNode = current;
        current = temp;
    }

    // Connect the reversed portion back to the linked list
    prev->next->next = current;
    prev->next = nextNode;

    return dummy->next;
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

    // Reverse the linked list from position 2 to 4
    int m = 2, n = 4;
    head = reverseBetween(head, m, n);

    // Display the modified linked list
    printf("Modified Linked List: ");
    display(head);

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}