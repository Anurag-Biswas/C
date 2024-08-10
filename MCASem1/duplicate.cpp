#include <stdio.h>
#include <stdbool.h>

// Function to remove duplicates from an array
void removeDuplicates(int arr[], int *size) {
    if (*size <= 1) {
        return;  // No duplicates to remove
    }

    // Initialize a hash table to keep track of seen elements
    bool seen[1000] = {false};  // Assuming a maximum element value of 1000

    int newSize = 0;  // Initialize the new size of the array

    for (int i = 0; i < *size; i++) {
        if (!seen[arr[i]]) {
            // If the current element has not been seen before
            arr[newSize] = arr[i];  // Store it in the new position
            seen[arr[i]] = true;  // Mark it as seen
            newSize++;
        }
    }

    *size = newSize;  // Update the size of the array
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    removeDuplicates(arr, &size);

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
