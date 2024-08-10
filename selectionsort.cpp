#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        // Assume the current index is the minimum
        minIndex = i;
        
        // Find the minimum element in the remaining unsorted array
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

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

    selectionSort(dataset, n);

    printf("Sorted dataset: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}
