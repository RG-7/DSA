/*
 * 6) Write a program to implement the following operations on a Sparse Matrix, assuming the
 *  matrix is represented using a triplet.
 * (a) Transpose of a matrix.
 * (b) Addition of two matrices.
 * (c) Multiplication of two matrices. 
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Sparse Matrix using Triplet format
typedef struct SparseMatrix {
    int rows, cols, num_non_zero;
    int *row_ind, *col_ind;
    double *values;
} SparseMatrix;

// Function to transpose a matrix
SparseMatrix transpose(SparseMatrix *mat) {
    SparseMatrix trans;
    trans.rows = mat->cols;
    trans.cols = mat->rows;
    trans.num_non_zero = mat->num_non_zero;

    trans.row_ind = (int *) malloc(mat->num_non_zero * sizeof(int));
    trans.col_ind = (int *) malloc(mat->num_non_zero * sizeof(int));
    trans.values = (double *) malloc(mat->num_non_zero * sizeof(double));

    for (int i = 0; i < mat->num_non_zero; i++) {
        trans.row_ind[i] = mat->col_ind[i];
        trans.col_ind[i] = mat->row_ind[i];
        trans.values[i] = mat->values[i];
    }

    return trans;
}

// Function to add two matrices
SparseMatrix add(SparseMatrix *mat1, SparseMatrix *mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Matrices cannot be added, dimensions do not match.\n");
        exit(0);
    }

    SparseMatrix sum;
    sum.rows = mat1->rows;
    sum.cols = mat1->cols;

    int num_non_zero = mat1->num_non_zero + mat2->num_non_zero;
    sum.row_ind = (int *) malloc(num_non_zero * sizeof(int));
    sum.col_ind = (int *) malloc(num_non_zero * sizeof(int));
    sum.values = (double *) malloc(num_non_zero * sizeof(double));

    int i = 0, j = 0, k = 0;
    while (i < mat1->num_non_zero && j < mat2->num_non_zero) {
        if (mat1->row_ind[i] < mat2->row_ind[j] ||
            (mat1->row_ind[i] == mat2->row_ind[j] && mat1->col_ind[i] < mat2->col_ind[j])) {
            sum.row_ind[k] = mat1->row_ind[i];
            sum.col_ind[k] = mat1->col_ind[i];
            sum.values[k] = mat1->values[i];
            i++;
        } else if (mat1->row_ind[i] > mat2->row_ind[j] ||
                   (mat1->row_ind[i] == mat2->row_ind[j] && mat1->col_ind[i] > mat2->col_ind[j])) {
            sum.row_ind[k] = mat2->row_ind[j];
            sum.col_ind[k] = mat2->col_ind[j];
            sum.values[k] = mat2->values[j];
            j++;
        } else {
            sum.row_ind[k] = mat1->row_ind[i];
            sum.col_ind[k] = mat1->col_ind[i];
            sum.values[k] = mat1->values[i] + mat2->values[j];
            i++;
            j++;
        }
        k++;
    }

    while (i < mat1->num_non_zero) {
        sum.row_ind[k] = mat1->row_ind[i];
        sum.col_ind[k] = mat1->col_ind[i];
        sum.values[k] = mat1->values[i];
        i++;
        k++;
    }

    while (j < mat2->num_non_zero) {
        sum.row_ind[k] = mat2->row_ind[j];
        sum.col_ind[k] = mat2->col_ind[j];
        sum.values[k] = mat2->values[j];
        j++;
        k++;
    }

    sum.num_non_zero = k;

    return sum;
}

// Function to multiply two matrices
SparseMatrix multiply(SparseMatrix *mat1, SparseMatrix *mat2) {
    if (mat1->cols != mat2->rows) {
        printf("Matrices cannot be multiplied, dimensions do not match.\n");
        exit(0);
    }

    SparseMatrix prod;
    prod.rows = mat1->rows;
    prod.cols = mat2->cols;

    int num_non_zero = mat1->num_non_zero + mat2->num_non_zero;
    prod.row_ind = (int *) malloc(num_non_zero * sizeof(int));
    prod.col_ind = (int *) malloc(num_non_zero * sizeof(int));
    prod.values = (double *) malloc(num_non_zero * sizeof(double));

    int i = 0, j = 0, k = 0;
    while (i < mat1->num_non_zero && j < mat2->num_non_zero) {
        if (mat1->col_ind[i] < mat2->row_ind[j]) {
            i++;
        } else if (mat1->col_ind[i] > mat2->row_ind[j]) {
            j++;
        } else {
            for (int l = 0; l < mat2->cols; l++) {
                prod.row_ind[k] = mat1->row_ind[i];
                prod.col_ind[k] = mat2->col_ind[l];
                prod.values[k] = mat1->values[i] * mat2->values[mat2->cols * j + l];
                k++;
            }
            i++;
            j++;
        }
    }

    prod.num_non_zero = k;

    return prod;
}

// Function to print a matrix
void print_matrix(SparseMatrix *mat) {
    for (int i = 0; i < mat->num_non_zero; i++) {
        printf("(%d, %d) = %lf\n", mat->row_ind[i], mat->col_ind[i], mat->values[i]);
    }
}

// Function to create a Sparse Matrix
SparseMatrix create_matrix(int rows, int cols, int num_non_zero, int *row_ind, int *col_ind, double *values) {
    SparseMatrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.num_non_zero = num_non_zero;

    mat.row_ind = (int *) malloc(num_non_zero * sizeof(int));
    mat.col_ind = (int *) malloc(num_non_zero * sizeof(int));
    mat.values = (double *) malloc(num_non_zero * sizeof(double));

    for (int i = 0; i < num_non_zero; i++) {
        mat.row_ind[i] = row_ind[i];
        mat.col_ind[i] = col_ind[i];
        mat.values[i] = values[i];
    }

    return mat;
}

// Function to clean up the memory occupied by a matrix
void clean_up(SparseMatrix *mat) {
    free(mat->row_ind);
    free(mat->col_ind);
    free(mat->values);
}

int main() {
    // Test matrices
    int rows = 4, cols = 4, num_non_zero = 7;
    int row_ind[] = {0, 0, 1, 1, 2, 2, 3};
    int col_ind[] = {0, 2, 1, 3, 2, 3, 3};
    double values[] = {1, 2, 3, 4, 5, 6, 7};

    SparseMatrix mat1 = create_matrix(rows, cols, num_non_zero, row_ind, col_ind, values);

    int rows2 = 4, cols2 = 4, num_non_zero2 = 7;
    int row_ind2[] = {0, 0, 1, 1, 2, 2, 3};
    int col_ind2[] = {0, 2, 1, 3, 2, 3, 3};
    double values2[] = {8, 9, 10, 11, 12, 13, 14};

    SparseMatrix mat2 = create_matrix(rows2, cols2, num_non_zero2, row_ind2, col_ind2, values2);

    // Print original matrices
    printf("Matrix 1:\n");
    print_matrix(&mat1);
    printf("\nMatrix 2:\n");
    print_matrix(&mat2);

    // Perform operations
    SparseMatrix sum = add(&mat1, &mat2);
    printf("\nSum of Matrices:\n");
    print_matrix(&sum);

    SparseMatrix prod = multiply(&mat1, &mat2);
    printf("\nProduct of Matrices:\n");
    print_matrix(&prod);

    // Clean up
    clean_up(&mat1);
    clean_up(&mat2);
    clean_up(&sum);
    clean_up(&prod);

    return 0;
}