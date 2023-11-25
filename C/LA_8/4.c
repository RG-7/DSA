/*
    Write a program to determine whether a given binary tree is a BST or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for a binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check whether a binary tree is a BST
bool isBSTUtil(struct Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data <= minValue || root->data >= maxValue)
        return false;

    return isBSTUtil(root->left, minValue, root->data) &&
           isBSTUtil(root->right, root->data, maxValue);
}

// Wrapper function to check whether a binary tree is a BST
bool isBST(struct Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    struct Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(18);

    if (isBST(root))
        printf("The given binary tree is a BST.\n");
    else
        printf("The given binary tree is not a BST.\n");

    return 0;
}