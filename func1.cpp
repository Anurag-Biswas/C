#include <stdio.h>

// Function to input a matrix
void inputMatrix(int matrix[10][10], int row, int col) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int row, col;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &row, &col);

    if (row <= 0 || col <= 0) {
        printf("Invalid input for matrix dimensions. Please enter positive values.\n");
        return 1;
    }

    printf("Matrix 1:\n");
    inputMatrix(mat1, row, col);
    printf("Matrix 2:\n");
    inputMatrix(mat2, row, col);

    printf("Matrix 1:\n");
    displayMatrix(mat1, row, col);
    printf("Matrix 2:\n");
    displayMatrix(mat2, row, col);

    // Menu for operation selection
    int choice;
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrices(mat1, mat2, result, row, col);
            printf("Result of Addition:\n");
            displayMatrix(result, row, col);
            break;
        case 2:
            subtractMatrices(mat1, mat2, result, row, col);
            printf("Result of Subtraction:\n");
            displayMatrix(result, row, col);
            break;
        default:
            printf("Invalid choice. Please select 1 for addition or 2 for subtraction.\n");
            break;
    }

    return 0;
}

