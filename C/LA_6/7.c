/*
    ADDITIONAL QUESTION 2
    Remove all even parity nodes from a Doubly and Circular Singly Linked List
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Node of the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a node at the beginning of the Doubly Linked List
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

// Function that returns true if count of set bits in x is even
bool isEvenParity(int x)
{
    int parity = 0;
    while (x)
    {
        parity ^= 1;  // Toggle the parity flag for every set bit
        x &= (x - 1); // Clear the least significant set bit
    }
    return (parity == 0);
}

// Function to delete a node in a Doubly Linked List.
void deleteNode(struct Node **head_ref, struct Node *del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

// Function to remove all the Even Parity Nodes from a doubly linked list
void deleteEvenParityNodes(struct Node **head_ref)
{
    struct Node *ptr = *head_ref;
    struct Node *next;

    while (ptr != NULL)
    {
        next = ptr->next;
        if (isEvenParity(ptr->data))
            deleteNode(head_ref, ptr);

        ptr = next;
    }
}

// Function to print nodes in a given doubly linked list
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver Code
int main()
{
    struct Node *head = NULL;

    // Create the doubly linked list: 18 <-> 15 <-> 8 <-> 9 <-> 14
    push(&head, 14);
    push(&head, 9);
    push(&head, 8);
    push(&head, 15);
    push(&head, 18);

    printf("Original List: ");
    printList(head);

    deleteEvenParityNodes(&head);

    printf("Modified List: ");
    printList(head);

    return 0;
}
