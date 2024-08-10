#include <stdio.h>

int main() {
    int n; // Size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n]; // Declare an array of size 'n'

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize min and max with the first element of the array
    int min = arr[0];
    int max = arr[0];

    // Find the minimum and maximum elements
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Smallest element: %d\n", min);
    printf("Largest element: %d\n", max);

    return 0;
}
