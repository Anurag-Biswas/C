#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

// Function to generate random array elements
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Generating random numbers between 0 and 999
    }
}

int main() {
    const int size = 100000;
    int arr1[size], arr2[size]; // Arrays for merge sort and quicksort

    // Generate random arrays
    generateRandomArray(arr1, size);
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i]; // Copy the same data for fair comparison
    }

    // Measure the time taken by merge sort
    clock_t mergeStart = clock();
    mergeSort(arr1, 0, size - 1);
    clock_t mergeEnd = clock();
    double mergeTime = ((double)(mergeEnd - mergeStart)) / CLOCKS_PER_SEC;

    // Measure the time taken by quicksort
    clock_t quickStart = clock();
    quickSort(arr2, 0, size - 1);
    clock_t quickEnd = clock();
    double quickTime = ((double)(quickEnd - quickStart)) / CLOCKS_PER_SEC;

    // Print execution times
    printf("Merge Sort Time: %f seconds\n", mergeTime);
    printf("Quick Sort Time: %f seconds\n", quickTime);

    return 0;
}

// Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
