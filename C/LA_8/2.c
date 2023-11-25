/*
    Implement following functions for Binary Search Trees
        (a) Search a given item (Recursive & Non-Recursive)
        (b) Maximum element of the BST
        (c) Minimum element of the BST
        (d) In-order successor of a given node the BST
        (e) In-order predecessor of a given node the BST
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary search tree
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

// (a) Recursive Search in BST
struct Node *recursiveSearch(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return recursiveSearch(root->left, key);
    else
        return recursiveSearch(root->right, key);
}

// (a) Non-Recursive Search in BST
struct Node *iterativeSearch(struct Node *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// (b) Find Maximum element in BST
struct Node *findMax(struct Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

// (c) Find Minimum element in BST
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// (d) In-order Successor in BST
struct Node *inOrderSuccessor(struct Node *root, struct Node *target)
{
    if (target->right != NULL)
        return findMin(target->right);

    struct Node *successor = NULL;
    while (root != NULL)
    {
        if (target->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}

// (e) In-order Predecessor in BST
struct Node *inOrderPredecessor(struct Node *root, struct Node *target)
{
    if (target->left != NULL)
        return findMax(target->left);

    struct Node *predecessor = NULL;
    while (root != NULL)
    {
        if (target->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data)
        {
            root = root->left;
        }
        else
        {
            break;
        }
    }
    return predecessor;
}

// Function to insert a key into the BST
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to perform in-order traversal
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
    {
        root = insert(root, keys[i]);
    }

    printf("In-order traversal of BST: ");
    inOrderTraversal(root);
    printf("\n");

    int searchKey = 60;
    struct Node *searchResultRecursive = recursiveSearch(root, searchKey);
    struct Node *searchResultIterative = iterativeSearch(root, searchKey);

    if (searchResultRecursive != NULL)
        printf("Recursive Search: Key %d found in the BST.\n", searchKey);
    else
        printf("Recursive Search: Key %d not found in the BST.\n", searchKey);

    if (searchResultIterative != NULL)
        printf("Iterative Search: Key %d found in the BST.\n", searchKey);
    else
        printf("Iterative Search: Key %d not found in the BST.\n", searchKey);

    struct Node *maxNode = findMax(root);
    printf("Maximum element in BST: %d\n", maxNode->data);

    struct Node *minNode = findMin(root);
    printf("Minimum element in BST: %d\n", minNode->data);

    struct Node *targetNode = iterativeSearch(root, searchKey);
    struct Node *successorNode = inOrderSuccessor(root, targetNode);
    struct Node *predecessorNode = inOrderPredecessor(root, targetNode);

    if (successorNode != NULL)
        printf("In-order Successor of %d: %d\n", searchKey, successorNode->data);
    else
        printf("In-order Successor of %d: No successor.\n", searchKey);

    if (predecessorNode != NULL)
        printf("In-order Predecessor of %d: %d\n", searchKey, predecessorNode->data);
    else
        printf("In-order Predecessor of %d: No predecessor.\n", searchKey);

    return 0;
}
