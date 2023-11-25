/*
    ADDITIONAL QUESTION 4
    Correct the Random Pointer in Doubly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Node of a doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Structure for the doubly linked list
struct DoubleLinkedList
{
    struct Node *head;
};

// Function to append a node in the DLL
void appendNode(struct DoubleLinkedList *ll, struct Node *n)
{
    struct Node *temp = ll->head;
    if (temp == NULL)
    {
        ll->head = n;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

// Function to print the DLL
void printList(struct DoubleLinkedList *ll)
{
    struct Node *temp = ll->head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the reverse of the DLL
void printReverse(struct DoubleLinkedList *ll)
{
    struct Node *temp = ll->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to correct the random pointer
void correctPointer(struct DoubleLinkedList *ll)
{
    if (!ll->head)
    {
        return;
    }
    struct Node *temp = ll->head;
    while (temp->next != NULL)
    {
        if (temp->next->prev != temp)
        {
            temp->next->prev = temp;
        }
        temp = temp->next;
    }
}

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Driver Code
int main()
{
    // Creating a DLL
    struct DoubleLinkedList ll;
    ll.head = NULL;

    // Appending nodes to the DLL
    appendNode(&ll, createNode(1));
    appendNode(&ll, createNode(2));
    appendNode(&ll, createNode(3));
    appendNode(&ll, createNode(4));

    printf("\nIncorrect Linked List: ");
    printList(&ll);
    printReverse(&ll);

    correctPointer(&ll);

    printf("\nCorrected Linked List: ");
    printList(&ll);
    printReverse(&ll);

    return 0;
}
