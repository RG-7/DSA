/*
    ADDITIONAL QUESTION 4
    Write a program to merge two BSTs into a doubly-linked list in sorted order.
    Example Input : 
                             20
                        T1 /    \
                          10    30
                               /   \
                              25    100

                            50
                        T2 / \
                          5 70
    Output:
        5 <—> 10 <—> 20 <—> 25 <—> 30 <—> 50 <—> 70 <—> 100 <—> null
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition for a doubly linked list node
struct ListNode {
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

// Function to perform in-order traversal of a BST and store the nodes in a linked list
void inOrderTraversal(struct TreeNode* root, struct ListNode** head) {
    if (root != NULL) {
        inOrderTraversal(root->left, head);

        // Create a new node for the linked list
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->data = root->data;
        newNode->prev = NULL;
        newNode->next = NULL;

        // If the linked list is empty, set the new node as the head
        if (*head == NULL) {
            *head = newNode;
        } else {
            // Otherwise, append the new node to the end of the linked list
            struct ListNode* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        inOrderTraversal(root->right, head);
    }
}

// Function to merge two sorted doubly linked lists into one
struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1->prev = current;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2->prev = current;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If one list is not empty, append the remaining nodes
    if (list1 != NULL) {
        current->next = list1;
        list1->prev = current;
    } else {
        current->next = list2;
        list2->prev = current;
    }

    // Return the merged list (excluding the dummy node)
    return dummy.next;
}

// Function to convert a doubly linked list to a BST
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    // Find the middle of the list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Create a new root node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = slow->data;

    // Recursively build the left and right subtrees
    if (prev != NULL) {
        prev->next = NULL; // Break the list into two halves
        root->left = sortedListToBST(head);
    }
    root->right = sortedListToBST(slow->next);

    return root;
}

// Function to merge two BSTs into a sorted doubly linked list
struct ListNode* mergeBSTs(struct TreeNode* root1, struct TreeNode* root2) {
    // Perform in-order traversal of each BST to create sorted doubly linked lists
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    inOrderTraversal(root1, &list1);
    inOrderTraversal(root2, &list2);

    // Merge the two sorted lists
    return mergeLists(list1, list2);
}

// Function to print a doubly linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

// Driver program
int main() {
    // Example usage
    struct TreeNode* tree1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->data = 20;
    tree1->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->left->data = 10;
    tree1->left->left = NULL;
    tree1->left->right = NULL;
    tree1->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->right->data = 30;
    tree1->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->right->left->data = 25;
    tree1->right->left->left = NULL;
    tree1->right->left->right = NULL;
    tree1->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->right->right->data = 100;
    tree1->right->right->left = NULL;
    tree1->right->right->right = NULL;

    struct TreeNode* tree2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->data = 50;
    tree2->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->left->data = 5;
    tree2->left->left = NULL;
    tree2->left->right = NULL;
    tree2->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->right->data = 70;
    tree2->right->left = NULL;
    tree2->right->right = NULL;

    // Merge the two BSTs into a doubly linked list
    struct ListNode* mergedList = mergeBSTs(tree1, tree2);

    // Print the merged list
    printf("Merged Doubly Linked List: ");
    printList(mergedList);

    return 0;
}
