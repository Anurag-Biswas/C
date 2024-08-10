#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;

        // Print the dataset after each iteration
        printf("After iteration %d: ", i);
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

    insertionSort(dataset, n);

    printf("Sorted dataset: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}
