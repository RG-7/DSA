/*
    Display all the node values in a circular linked list, repeating value of head node at the end too. For example, if elements present in the circular linked list starting from
    head are 20 → 100 → 40 → 80 → 60, then output should be displayed as 20 100 40 80 60 20.
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
        head->next = head; // Point to itself in a circular list
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

// Function to display the Circular Linked List, repeating head value at the end
void displayRepeatHead(struct Node *head)
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
    printf("%d\n", head->data); // Repeat the head value at the end
}

// Function to free the memory allocated for the Circular Linked List
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
    int value, n;

    printf("Enter the number of elements in the Circular Linked List: ");
    scanf("%d", &n);

    printf("Enter the elements of the Circular Linked List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Circular Linked List with repeated head value at the end: ");
    displayRepeatHead(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
