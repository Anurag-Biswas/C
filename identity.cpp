#include <stdio.h>

int isIdentityMatrix(int mat[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if the main diagonal elements are 1 and others are 0
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                return 0; // Not an identity matrix
            }
        }
    }
    return 1; // It's an identity matrix
}

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[10][10];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isIdentityMatrix(matrix, n)) {
        printf("It is an identity matrix.\n");
    } else {
        printf("It is not an identity matrix.\n");
    }

    return 0;
}
