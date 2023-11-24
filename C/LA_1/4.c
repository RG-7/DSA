/*
    4) Implement the logic to
        a. Reverse the elements of an array
        b. Find the matrix multiplication
        c. Find the Transpose of a Matrix
*/

#include <stdio.h>

#define MAX_SIZE 10

// Function to reverse the elements of an array
void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move indices towards the center
        start++;
        end--;
    }
}

// Function to perform matrix multiplication
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2)
{
    if (cols1 != rows2)
    {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to find the transpose of a matrix
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int trans[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            trans[j][i] = mat[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int array[MAX_SIZE];
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Reverse the elements of an array
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    reverseArray(array, size);

    printf("Reversed array elements: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Matrix multiplication
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows2; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    printf("Matrix multiplication result:\n");
    displayMatrix(result, rows1, cols2);

    // Transpose of a matrix
    transposeMatrix(matrix1, transposed, rows1, cols1);

    printf("Transpose of the first matrix:\n");
    displayMatrix(transposed, cols1, rows1);

    return 0;
}
