/*
    ADDITIONAL QUESTION 2
    Given a list, rotate the list to the right by k places, where k is non-negative.
    Example Input
        A = 1->2->3->4->5->NULL
        B = 2
    Example Output
        4->5->1->2->3->NULL
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to find the length of the linked list
int findLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

// Function to rotate the linked list to the right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    int length = findLength(head);
    k = k % length;

    if (k == 0) {
        return head;
    }

    struct Node* dummy = createNode(0);
    dummy->next = head;
    struct Node* fast = dummy;
    struct Node* slow = dummy;

    // Move fast k steps ahead
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Rotate the linked list
    struct Node* newHead = slow->next;
    slow->next = NULL;
    fast->next = dummy->next;

    return newHead;
}

// Function to display all node values in the linked list
void display(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Example: Creating a linked list with given values
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Display the original linked list
    printf("Original Linked List: ");
    display(head);

    // Rotate the linked list to the right by 2 places
    int k = 2;
    head = rotateRight(head, k);

    // Display the rotated linked list
    printf("Rotated Linked List: ");
    display(head);

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
