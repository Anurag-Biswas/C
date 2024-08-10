#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Print the dataset after each iteration
        printf("After iteration (pivot=%d): ", arr[pivotIndex]);
        for (int k = 0; k <= high; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(dataset, 0, n - 1);

    printf("Sorted dataset: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}
