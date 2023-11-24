/*
    5.) Write a program to find sum of every row and every column in a two-dimensional array.
*/

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to find the sum of every row
void rowSum(int mat[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    printf("Sum of every row:\n");
    for (int i = 0; i < rows; ++i)
    {
        int sum = 0;
        for (int j = 0; j < cols; ++j)
        {
            sum += mat[i][j];
        }
        printf("Row %d: %d\n", i + 1, sum);
    }
}

// Function to find the sum of every column
void colSum(int mat[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    printf("\nSum of every column:\n");
    for (int j = 0; j < cols; ++j)
    {
        int sum = 0;
        for (int i = 0; i < rows; ++i)
        {
            sum += mat[i][j];
        }
        printf("Column %d: %d\n", j + 1, sum);
    }
}

int main()
{
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    // Input the number of rows and columns
    printf("Enter the number of rows and columns (<= %d): ", MAX_ROWS);
    scanf("%d %d", &rows, &cols);

    // Input elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("\nMatrix elements:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Find the sum of every row and every column
    rowSum(matrix, rows, cols);
    colSum(matrix, rows, cols);

    return 0;
}