/*
    ADDITIONAL QUESTION 2
    Given preorder and in-order traversals, write a program to construct the Binary Tree.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to search for an element in the in-order array
int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1; // Not found
}

// Recursive function to construct a binary tree from pre-order, in-order, and post-order traversals
struct TreeNode *buildTreeHelper(int pre[], int in[], int post[], int inStart, int inEnd, int *preIndex)
{
    // Base case
    if (inStart > inEnd)
    {
        return NULL;
    }

    // Create a new node with the current element from pre-order traversal
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = pre[(*preIndex)++];
    root->left = NULL;
    root->right = NULL;

    // Find the index of the current root element in in-order traversal
    int inIndex = search(in, inStart, inEnd, root->data);

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(pre, in, post, inStart, inIndex - 1, preIndex);
    root->right = buildTreeHelper(pre, in, post, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to construct a binary tree from pre-order, in-order, and post-order traversals
struct TreeNode *buildTree(int pre[], int in[], int post[], int size)
{
    int preIndex = 0;
    return buildTreeHelper(pre, in, post, 0, size - 1, &preIndex);
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Driver program
int main()
{
    // Example usage
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode *root = buildTree(preorder, inorder, postorder, size);

    printf("In-order traversal of constructed tree: ");
    inOrderTraversal(root);

    return 0;
}
