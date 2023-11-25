/*
    Write a program to check if a doubly linked list of characters is palindrome or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for Doubly Linked List
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node *createNode(char value)
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
struct Node *insertAtEnd(struct Node *head, char value)
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

// Function to check if a doubly linked list is palindrome or not
bool isPalindrome(struct Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    struct Node *start = head;
    struct Node *end = head;

    // Move 'end' to the last node
    while (end->next != NULL)
    {
        end = end->next;
    }

    while (start != end && start->prev != end)
    {
        if (start->data != end->data)
        {
            return false;
        }

        start = start->next;
        end = end->prev;
    }

    return true;
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
    char str[100];

    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", str);

    // Create a doubly linked list from the string
    for (int i = 0; str[i] != '\0'; i++)
    {
        head = insertAtEnd(head, str[i]);
    }

    if (isPalindrome(head))
    {
        printf("The given string is a palindrome.\n");
    }
    else
    {
        printf("The given string is not a palindrome.\n");
    }

    // Free allocated memory
    freeDoublyList(head);

    return 0;
}
