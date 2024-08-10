#include <stdio.h>

int main() {
    int originalMatrix[10][10], transposedMatrix[10][10];
    int rows, columns;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &columns);

    // Input the elements of the original matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &originalMatrix[i][j]);
        }
    }

    // Transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    // Display the transposed matrix
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
