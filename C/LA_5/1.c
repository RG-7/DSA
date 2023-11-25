/*
    Develop a menu driven program for the following operations of on a Singly LinkedList.
        (a) Insertion at the beginning.
        (b) Insertion at the end.
        (c) Insertion in between (before or after a node having a specific value, say 'Insert a new Node 35 before/after the Node 30').
        (d) Deletion from the beginning.
        (e) Deletion from the end.
        (f) Deletion of a specific node, say 'Delete Node 60').
        (g) Search for a node and display its position from head.
        (h) Display all the node values.
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

// Function to insert a node at the beginning of the linked list
struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
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

// Function to insert a node after a specific value in the linked list
struct Node *insertAfterValue(struct Node *head, int targetValue, int newValue)
{
    struct Node *newNode = createNode(newValue);

    struct Node *current = head;
    while (current != NULL && current->data != targetValue)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with value %d not found.\n", targetValue);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the linked list
struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node with a specific value from the linked list
struct Node *deleteNodeWithValue(struct Node *head, int targetValue)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return NULL;
    }

    if (head->data == targetValue)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    while (current->next != NULL && current->next->data != targetValue)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Node with value %d not found.\n", targetValue);
        return head;
    }

    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to search for a node and display its position from head
void searchAndDisplay(struct Node *head, int targetValue)
{
    int position = 1;
    struct Node *current = head;

    while (current != NULL && current->data != targetValue)
    {
        current = current->next;
        position++;
    }

    if (current == NULL)
    {
        printf("Node with value %d not found.\n", targetValue);
    }
    else
    {
        printf("Node with value %d found at position %d from head.\n", targetValue, position);
    }
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

// Main function for the menu-driven program
int main()
{
    struct Node *head = NULL;
    int choice, value, targetValue;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insertion at the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion in between (before or after a specific value)\n");
        printf("4. Deletion from the beginning\n");
        printf("5. Deletion from the end\n");
        printf("6. Deletion of a specific node\n");
        printf("7. Search for a node and display its position from head\n");
        printf("8. Display all node values\n");
        printf("9. Exit\n");
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
            printf("Enter the specific value after which to insert a new node: ");
            scanf("%d", &targetValue);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            head = insertAfterValue(head, targetValue, value);
            break;
        case 4:
            head = deleteFromBeginning(head);
            break;
        case 5:
            head = deleteFromEnd(head);
            break;
        case 6:
            printf("Enter the value of the node to delete: ");
            scanf("%d", &targetValue);
            head = deleteNodeWithValue(head, targetValue);
            break;
        case 7:
            printf("Enter the value to search and display its position from head: ");
            scanf("%d", &targetValue);
            searchAndDisplay(head, targetValue);
            break;
        case 8:
            display(head);
            break;
        case 9:
            // Free the memory allocated for the linked list before exiting
            freeLinkedList(head);
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 9);

    return 0;
}