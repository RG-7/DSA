/*
    Develop a menu driven program for the following operations of on a Circular as well as a Doubly Linked List.
        (a) Insertion anywhere in the linked list (As a first node, as a last node, and after/before a specific node).
        (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be deleted may appear as a head node, last node or a node in between.
        (c) Search for a node.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Doubly Linked List
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

// Function to insert a node at the beginning of the Circular Doubly Linked List
struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        head->next = head->prev = head; // Point to itself in a circular list
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

// Function to insert a node at the end of the Circular Doubly Linked List
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        head->next = head->prev = head; // Point to itself in a circular list
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    return head;
}

// Function to insert a node after a specific node in the Circular Doubly Linked List
struct Node *insertAfterNode(struct Node *head, int nodeValue, int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot insert after a specific node.\n");
        return head;
    }

    struct Node *current = head;
    while (current->data != nodeValue && current->next != head)
    {
        current = current->next;
    }

    if (current->data != nodeValue)
    {
        printf("Node with value %d not found in the list.\n", nodeValue);
        return head;
    }

    struct Node *newNode = createNode(value);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    return head;
}

// Function to delete a specific node from the Circular Doubly Linked List
struct Node *deleteNode(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete node.\n");
        return head;
    }

    struct Node *current = head;
    while (current->data != value && current->next != head)
    {
        current = current->next;
    }

    if (current->data != value)
    {
        printf("Node with value %d not found in the list.\n", value);
        return head;
    }

    if (head == current)
    {
        head = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);

    return head;
}

// Function to search for a node in the Circular Doubly Linked List
void searchNode(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot search for node.\n");
        return;
    }

    struct Node *current = head;
    int position = 1;
    do
    {
        if (current->data == value)
        {
            printf("Node with value %d found at position %d.\n", value, position);
            return;
        }
        current = current->next;
        position++;
    } while (current != head);

    printf("Node with value %d not found in the list.\n", value);
}

// Function to display the Circular Doubly Linked List
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to free the memory allocated for the Circular Doubly Linked List
void freeList(struct Node *head)
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
    int choice, value, nodeValue;

    do
    {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specific node\n");
        printf("4. Delete a specific node\n");
        printf("5. Search for a node\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;
        case 2:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;
        case 3:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the value of the node after which to insert: ");
            scanf("%d", &nodeValue);
            head = insertAfterNode(head, nodeValue, value);
            break;
        case 4:
            printf("Enter the value of the node to delete: ");
            scanf("%d", &value);
            head = deleteNode(head, value);
            break;
        case 5:
            printf("Enter the value to search for: ");
            scanf("%d", &value);
            searchNode(head, value);
            break;
        case 6:
            printf("Circular Doubly Linked List: ");
            display(head);
            break;
        case 7:
            freeList(head);
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}