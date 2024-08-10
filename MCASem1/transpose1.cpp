#include <stdio.h>

int main() {
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int matrix[rows][columns];

    // Input the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the matrix
    int transpose[columns][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Display the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Display the transposed matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
