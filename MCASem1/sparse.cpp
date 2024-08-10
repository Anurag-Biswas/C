#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int isSparseMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, double threshold) {
    int zeroCount = 0;
    int totalElements = rows * cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    // Calculate the ratio of zero elements to total elements
    double zeroRatio = (double)zeroCount / totalElements;

    // If the zeroRatio is greater than the threshold, consider it a sparse matrix
    if (zeroRatio > threshold) {
        return 1; // It's a sparse matrix
    } else {
        return 0; // It's not a sparse matrix
    }
}

int main() {
    int rows, cols;
    double threshold;
    int matrix[MAX_ROWS][MAX_COLS];

    // Input matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Input the threshold value
    printf("Enter the threshold value (e.g., 0.5): ");
    scanf("%lf", &threshold);

    if (isSparseMatrix(matrix, rows, cols, threshold)) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}
