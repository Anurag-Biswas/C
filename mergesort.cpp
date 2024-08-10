#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;

        // Print the dataset after each iteration
        printf("After iteration: ");
        for (int m = left; m <= right; m++) {
            printf("%d ", arr[m]);
        }
        printf("\n");
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

        // Print the dataset after each iteration
        printf("After iteration: ");
        for (int m = left; m <= right; m++) {
            printf("%d ", arr[m]);
        }
        printf("\n");
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

        // Print the dataset after each iteration
        printf("After iteration: ");
        for (int m = left; m <= right; m++) {
            printf("%d ", arr[m]);
        }
        printf("\n");
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    mergeSort(dataset, 0, n - 1);

    printf("Sorted dataset: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}
