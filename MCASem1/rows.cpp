#include <stdio.h>

int main() {
    int rows, cols, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize two matrices with the specified dimensions
    int matrix1[rows][cols], matrix2[rows][cols];

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of matrices
    int sumMatrix[rows][cols];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Subtraction of matrices
    int diffMatrix[rows][cols];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            diffMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Display the sum matrix
    printf("Sum of the two matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", sumMatrix[i][j]);
        }
        printf("\n");
    }

    // Display the difference matrix
    printf("Difference of the two matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", diffMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
