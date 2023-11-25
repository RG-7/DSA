/*
 * 5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
 *  𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices, implement an
 *  efficient way that reduces the space requirement.
 *      (a) Diagonal Matrix.
 *      (b) Tri-diagonal Matrix.
 *      (c) Lower triangular Matrix.
 *      (d) Upper triangular Matrix.
 *      (e) Symmetric Matrix 
 */

#include <stdio.h>

#define SIZE 100

// Diagonal Matrix
typedef struct {
    int data[SIZE];
    int size;
} DiagonalMatrix;

int getDiagonal(DiagonalMatrix* mat, int i, int j) {
    if (i == j && i < mat->size) {
        return mat->data[i];
    } else {
        return 0; // Assuming 0 for elements outside the diagonal
    }
}

void setDiagonal(DiagonalMatrix* mat, int i, int j, int value) {
    if (i == j && i < mat->size) {
        mat->data[i] = value;
    } else {
        // Ignoring elements outside the diagonal
    }
}

// Tri-diagonal Matrix
typedef struct {
    int data[3 * SIZE - 2];
    int size;
} TriDiagonalMatrix;

int getTriDiagonal(TriDiagonalMatrix* mat, int i, int j) {
    if (i - j == 1) {
        return mat->data[i - 1]; // Lower diagonal
    } else if (i == j) {
        return mat->data[SIZE + i - 1]; // Main diagonal
    } else if (j - i == 1) {
        return mat->data[2 * SIZE + i - 1]; // Upper diagonal
    } else {
        return 0; // Assuming 0 for elements outside the tri-diagonal
    }
}

void setTriDiagonal(TriDiagonalMatrix* mat, int i, int j, int value) {
    if (i - j == 1) {
        mat->data[i - 1] = value; // Lower diagonal
    } else if (i == j) {
        mat->data[SIZE + i - 1] = value; // Main diagonal
    } else if (j - i == 1) {
        mat->data[2 * SIZE + i - 1] = value; // Upper diagonal
    } else {
        // Ignoring elements outside the tri-diagonal
    }
}

// Lower Triangular Matrix
typedef struct {
    int data[SIZE * (SIZE + 1) / 2];
    int size;
} LowerTriangularMatrix;

int getLowerTriangular(LowerTriangularMatrix* mat, int i, int j) {
    if (i >= j && i < mat->size && j < mat->size) {
        return mat->data[i * (i + 1) / 2 + j];
    } else {
        return 0; // Assuming 0 for elements outside the lower triangular
    }
}

void setLowerTriangular(LowerTriangularMatrix* mat, int i, int j, int value) {
    if (i >= j && i < mat->size && j < mat->size) {
        mat->data[i * (i + 1) / 2 + j] = value;
    } else {
        // Ignoring elements outside the lower triangular
    }
}

// Upper Triangular Matrix
typedef struct {
    int data[SIZE * (SIZE + 1) / 2];
    int size;
} UpperTriangularMatrix;

int getUpperTriangular(UpperTriangularMatrix* mat, int i, int j) {
    if (i <= j && i < mat->size && j < mat->size) {
        return mat->data[i * (2 * mat->size - i - 1) / 2 + j - i];
    } else {
        return 0; // Assuming 0 for elements outside the upper triangular
    }
}

void setUpperTriangular(UpperTriangularMatrix* mat, int i, int j, int value) {
    if (i <= j && i < mat->size && j < mat->size) {
        mat->data[i * (2 * mat->size - i - 1) / 2 + j - i] = value;
    } else {
        // Ignoring elements outside the upper triangular
    }
}

// Symmetric Matrix
typedef struct {
    int data[SIZE * (SIZE + 1) / 2];
    int size;
} SymmetricMatrix;

int getSymmetric(SymmetricMatrix* mat, int i, int j) {
    if (i < mat->size && j < mat->size) {
        if (i >= j) {
            return mat->data[i * (i + 1) / 2 + j];
        } else {
            return mat->data[j * (j + 1) / 2 + i];
        }
    } else {
        return 0; // Assuming 0 for elements outside the symmetric matrix
    }
}

void setSymmetric(SymmetricMatrix* mat, int i, int j, int value) {
    if (i < mat->size && j < mat->size) {
        if (i >= j) {
            mat->data[i * (i + 1) / 2 + j] = value;
        } else {
            mat->data[j * (j + 1) / 2 + i] = value;
        }
    } else {
        // Ignoring elements outside the symmetric matrix
    }
}

// Function to take user input for matrix elements
void inputMatrixElements(int matrix[][SIZE], int rows, int columns) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[][SIZE], int rows, int columns) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, columns;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int matrix[SIZE][SIZE];

    inputMatrixElements(matrix, rows, columns);

    // Example usage for each matrix type
    DiagonalMatrix diagMat;
    diagMat.size = (rows < columns) ? rows : columns; // Assuming square matrix
    for (int i = 0; i < diagMat.size; ++i) {
        setDiagonal(&diagMat, i, i, matrix[i][i]);
    }

    TriDiagonalMatrix triDiagMat;
    triDiagMat.size = (rows < columns) ? rows : columns; // Assuming square matrix
    for (int i = 0; i < triDiagMat.size; ++i) {
        setTriDiagonal(&triDiagMat, i, i, matrix[i][i]);
        if (i + 1 < triDiagMat.size) {
            setTriDiagonal(&triDiagMat, i + 1, i, matrix[i + 1][i]);
            setTriDiagonal(&triDiagMat, i, i + 1, matrix[i][i + 1]);
        }
    }

    LowerTriangularMatrix lowerTriMat;
    lowerTriMat.size = (rows < columns) ? rows : columns; // Assuming square matrix
    for (int i = 0; i < lowerTriMat.size; ++i) {
        for (int j = 0; j <= i; ++j) {
            setLowerTriangular(&lowerTriMat, i, j, matrix[i][j]);
        }
    }

    UpperTriangularMatrix upperTriMat;
    upperTriMat.size = (rows < columns) ? rows : columns; // Assuming square matrix
    for (int i = 0; i < upperTriMat.size; ++i) {
        for (int j = i; j < upperTriMat.size; ++j) {
            setUpperTriangular(&upperTriMat, i, j, matrix[i][j]);
        }
    }

    SymmetricMatrix symMat;
    symMat.size = (rows < columns) ? rows : columns; // Assuming square matrix
    for (int i = 0; i < symMat.size; ++i) {
        for (int j = 0; j <= i; ++j) {
            setSymmetric(&symMat, i, j, matrix[i][j]);
        }
    }

    // Print the matrices
    printMatrix(matrix, rows, columns);

    return 0;
}
