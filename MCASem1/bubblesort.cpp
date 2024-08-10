#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        // Print the dataset after each iteration
        printf("After iteration %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int dataset[] = {27,15,39,21,28,70};
    int n = sizeof(dataset) / sizeof(dataset[0]);

    printf("Original dataset: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    bubbleSort(dataset, n);

    printf("Sorted dataset: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}
