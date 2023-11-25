/*
    Write a program to count the number of occurrences of a given key in a singly linkedlist and then delete all the occurrences. For example, if given linked list is
    1->2->1->2->1->3->1 and given key is 1, then output should be 4. After deletion of all the occurrences of 1, the linked list is 2->2->3.
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

// Function to count occurrences and delete all occurrences of a key in the linked list
int countAndDeleteOccurrences(struct Node **head, int key)
{
    if (*head == NULL)
    {
        return 0;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    int count = 0;

    // Traverse the list to count and delete occurrences
    while (current != NULL)
    {
        if (current->data == key)
        {
            // Delete the current node
            struct Node *temp = current;
            if (prev == NULL)
            {
                // If the key is at the beginning
                *head = current->next;
                current = *head;
            }
            else
            {
                prev->next = current->next;
                current = current->next;
            }
            free(temp);
            count++;
        }
        else
        {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }

    return count;
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
    int key, count;

    // Example: Creating a linked list with given values
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 1);

    // Display the original linked list
    printf("Original Linked List: ");
    display(head);

    // Input the key to count and delete occurrences
    printf("Enter the key to count and delete: ");
    scanf("%d", &key);

    // Count and delete occurrences
    count = countAndDeleteOccurrences(&head, key);

    // Display the modified linked list
    printf("Linked List after deleting %d (occurrences: %d): ", key, count);
    display(head);

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
