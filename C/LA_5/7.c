/*
    ADDITIONAL QUESTION 3
    Adding two polynomials using Linked List

    Example 1:
        Input:
            1st number = 5x2 + 4x1 + 2x0
            2nd number = -5x1 - 5x0
        Output:
            5x2-1x1-3x0

    Example 2:
        Input:
            1st number = 5x3 + 4x2 + 2x0
            2nd number = 5x^1 - 5x^0
        Output:
            5x3 + 4x2 + 5x1 - 3x0
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of variable
struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create a new node
void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = (struct Node *)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

// Function to add two polynomial numbers
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly)
{
    while (poly1->next && poly2->next)
    {
        // If power of 1st polynomial is greater than 2nd,
        // then store 1st as it is and move its pointer
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        // If power of 2nd polynomial is greater than 1st,
        // then store 2nd as it is and move its pointer
        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then
        // add their coefficients
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create a new node
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }

    // Copy the remaining terms of poly1, if any
    while (poly1->next)
    {
        poly->pow = poly1->pow;
        poly->coeff = poly1->coeff;
        poly1 = poly1->next;

        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }

    // Copy the remaining terms of poly2, if any
    while (poly2->next)
    {
        poly->pow = poly2->pow;
        poly->coeff = poly2->coeff;
        poly2 = poly2->next;

        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

// Function to display the linked list
void show(struct Node *node)
{
    while (node->next != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0)
        {
            if (node->next != NULL)
                printf(" + ");
        }
    }
}

// Driver code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    // Create the first list: 5x^2 + 4x^1 + 2x^0
    create_node(5, 2, &poly1);
    create_node(4, 1, &poly1);
    create_node(2, 0, &poly1);

    // Create the second list: -5x^1 - 5x^0
    create_node(-5, 1, &poly2);
    create_node(-5, 0, &poly2);

    printf("1st Number: ");
    show(poly1);

    printf("\n2nd Number: ");
    show(poly2);

    poly = (struct Node *)malloc(sizeof(struct Node));

    // Add two polynomial numbers
    polyadd(poly1, poly2, poly);

    // Display the resultant polynomial
    printf("\nAdded polynomial: ");
    show(poly);

    return 0;
}
