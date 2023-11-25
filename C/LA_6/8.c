/*
    ADDITIONAL QUESTION 3
    Reverse a doubly linked list in groups of given size
*/

#include <stdio.h>
#include <stdlib.h>

// a node of the doubly linked list
struct Node
{
    int data;
    struct Node *next, *prev;
};

// function to get a new node
struct Node *getNode(int data)
{
    // allocate space
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node **head_ref, struct Node *new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list of the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// function to reverse a doubly linked list
// in groups of given size
struct Node *revListInGroupOfGivenSize(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *newHead = NULL;
    int count = 0;

    // reversing the current group of k
    // or less than k nodes by adding
    // them at the beginning of list
    // 'newHead'
    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }

    // if next group exists then making the desired
    // adjustments in the link
    if (next != NULL)
    {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }

    // pointer to the new head of the
    // reversed group
    // pointer to the new head should point to NULL, otherwise you won't be able to traverse list in reverse order using 'prev'
    newHead->prev = NULL;
    return newHead;
}

// Function to print nodes in a
// given doubly linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Driver program to test above
int main()
{
    // Start with the empty list
    struct Node *head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));

    int k = 2;

    printf("Original list: ");
    printList(head);

    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);

    printf("\nModified list: ");
    printList(head);

    return 0;
}
