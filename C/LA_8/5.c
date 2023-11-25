/*
    ADDITIONAL QUESTION 1
    Write a non-recursive function to traverse a BST in in-order traversal using stack.
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

// Structure to represent a stack
struct Stack
{
    struct TreeNode **array;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct TreeNode **)malloc(stack->capacity * sizeof(struct TreeNode *));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push a node onto the stack
void push(struct Stack *stack, struct TreeNode *node)
{
    stack->array[++stack->top] = node;
}

// Function to pop a node from the stack
struct TreeNode *pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Function for in-order traversal of BST using a stack
void inOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    struct Stack *stack = createStack(100); // Assuming a maximum of 100 nodes

    struct TreeNode *current = root;

    while (current != NULL || !isEmpty(stack))
    {
        // Reach the leftmost node of the current node
        while (current != NULL)
        {
            push(stack, current);
            current = current->left;
        }

        // Pop the node at the top of the stack
        current = pop(stack);
        printf("%d ", current->data);

        // Move to the right subtree
        current = current->right;
    }

    free(stack->array);
    free(stack);
}

// Function to create a new node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    // Example usage
    struct TreeNode *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("In-order traversal: ");
    inOrderTraversal(root);

    return 0;
}
