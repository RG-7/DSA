/*
    ADDITIONAL QUESTION 5
    Construct a Doubly linked linked list from 2D Matrix
*/

#include <stdio.h>
#include <stdlib.h>

// define dimension of matrix
#define dim 3

// struct node of doubly linked
// list with four pointer
// next, prev, up, down
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    struct Node* up;
    struct Node* down;
};

// function to create a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    temp->up = NULL;
    temp->down = NULL;
    return temp;
}

// function to construct the
// doubly linked list
struct Node* constructDoublyListUtil(
    int mtrx[][dim], int i, int j, struct Node* curr) {

    if (i >= dim || j >= dim) {
        return NULL;
    }

    // Create Node with value contain
    // in matrix at index (i, j)
    struct Node* temp = createNode(mtrx[i][j]);

    // Assign address of curr into
    // the prev pointer of temp
    temp->prev = curr;

    // Assign address of curr into
    // the up pointer of temp
    temp->up = curr;

    // Recursive call for next pointer
    temp->next = constructDoublyListUtil(mtrx, i, j + 1, temp);

    // Recursive call for down pointer
    temp->down = constructDoublyListUtil(mtrx, i + 1, j, temp);

    // Return newly constructed node
    // whose all four node connected
    // at its appropriate position
    return temp;
}

// Function to construct the doubly linked list
struct Node* constructDoublyList(int mtrx[][dim]) {
    // function call for construct
    // the doubly linked list
    return constructDoublyListUtil(mtrx, 0, 0, NULL);
}

// function for displaying
// doubly linked list data
void display(struct Node* head) {
    // pointer to move right
    struct Node* rPtr;

    // pointer to move down
    struct Node* dPtr = head;

    // loop till node->down is not NULL
    while (dPtr) {

        rPtr = dPtr;

        // loop till node->right is not NULL
        while (rPtr) {
            printf("%d ", rPtr->data);
            rPtr = rPtr->next;
        }

        printf("\n");
        dPtr = dPtr->down;
    }
}

// driver code
int main() {

    // initialise matrix
    int mtrx[dim][dim] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    struct Node* list = constructDoublyList(mtrx);

    display(list);

    return 0;
}
