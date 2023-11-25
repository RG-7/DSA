/*
    Write a program for binary search tree (BST) having functions for the following operations:
        (a) Insert an element (no duplicates are allowed),
        (b) Delete an existing element,
        (c) Maximum depth of BST
        (d) Minimum depth of 
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// (a) Function to insert an element into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// (b) Function to delete a node with a given key from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// (c) Function to find the maximum depth of BST
int maxDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

// (d) Function to find the minimum depth of BST
int minDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return (leftDepth < rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

// Function to perform in-order traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    printf("In-order traversal of BST: ");
    inOrderTraversal(root);
    printf("\n");

    int deleteKey = 40;
    printf("Deleting node with key %d\n", deleteKey);
    root = deleteNode(root, deleteKey);

    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    int maxDepthValue = maxDepth(root);
    printf("Maximum depth of BST: %d\n", maxDepthValue);

    int minDepthValue = minDepth(root);
    printf("Minimum depth of BST: %d\n", minDepthValue);

    return 0;
}
