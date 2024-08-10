#include <stdio.h>

// Function to add two 2x2 matrices using pointers
void addMatrices(int mat1[2][2], int mat2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            *(*(result + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}

int main() {
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    int matrix2[2][2] = {{5, 6}, {7, 8}};
    int resultMatrix[2][2];

    addMatrices(matrix1, matrix2, resultMatrix);

    // Display the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
