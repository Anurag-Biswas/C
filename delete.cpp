#include <stdio.h>

// Function to delete an element from a specific position in an array
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position. Deletion failed.\n");
        return;
    }

    // Shift elements to the left to overwrite the element at the given position
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int position;

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the position to delete (0-%d): ", size - 1);
    scanf("%d", &position);

    deleteElement(arr, &size, position);

    printf("Updated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}





