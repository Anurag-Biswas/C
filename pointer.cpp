#include <stdio.h>

int main() {
    int n;

    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size 'n'
    int *ptr = arr; // Initialize a pointer to the array

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i); // Use pointer arithmetic to access elements
    }

    // Print array elements using pointer
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i)); // Use pointer arithmetic to access elements
    }
    printf("\n");

    return 0;
}

