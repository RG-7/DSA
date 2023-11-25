/*
    ADDITIONAL QUESTION 3
    Given in-order and post-order traversals, write a program to construct the Binary Tree.
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

// Recursive function to construct a binary tree from in-order and post-order traversals
struct TreeNode *buildTreeHelper(int in[], int post[], int inStart, int inEnd, int *postIndex)
{
    // Base case
    if (inStart > inEnd)
    {
        return NULL;
    }

    // Create a new node with the current element from post-order traversal
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = post[(*postIndex)--];
    root->left = NULL;
    root->right = NULL;

    // Find the index of the current root element in in-order traversal
    int inIndex = search(in, inStart, inEnd, root->data);

    // Recursively build right and left subtrees
    root->right = buildTreeHelper(in, post, inIndex + 1, inEnd, postIndex);
    root->left = buildTreeHelper(in, post, inStart, inIndex - 1, postIndex);

    return root;
}

// Function to construct a binary tree from in-order and post-order traversals
struct TreeNode *buildTree(int in[], int post[], int size)
{
    int postIndex = size - 1;
    return buildTreeHelper(in, post, 0, size - 1, &postIndex);
}

// Function to perform post-order traversal of the binary tree
void postOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Driver program
int main()
{
    // Example usage
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int size = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode *root = buildTree(inorder, postorder, size);

    printf("Post-order traversal of constructed tree: ");
    postOrderTraversal(root);

    return 0;
}
