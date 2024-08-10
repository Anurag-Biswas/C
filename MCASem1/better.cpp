#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
void printArray(int arr[], int n);

// Main function
int main() {
    int n = 10000; // Size of the array
    int arr1[n], arr2[n]; // Arrays for bubble sort and quick sort
    clock_t start, end;
    double time_bubble, time_quick;

    // Fill arrays with random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];
    }

    // Measure time for bubble sort
    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    time_bubble = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Measure time for quick sort
    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    time_quick = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort: %f seconds\n", time_bubble);
    printf("Time taken for quick sort: %f seconds\n", time_quick);

    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
    return (i + 1);
}

// Utility function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

