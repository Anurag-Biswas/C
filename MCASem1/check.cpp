#include <stdio.h>

int main() {
    int n; // Number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number of elements.\n");
        return 1;
    }

    int arr[n]; // Declare an array of size 'n'

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int largest = arr[0];

    // Find the smallest and largest elements in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Print the smallest and largest elements
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);

    return 0;
}
