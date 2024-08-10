#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE];
    int size, position, newValue;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input the elements of the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Input the position and value to insert
    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &position);
    
    if (position < 0 || position > size) {
        printf("Invalid position. Position should be between 0 and %d\n", size);
        return 1;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &newValue);

    // Shift elements to make space for the new element
    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }

    // Insert the new value at the specified position
    array[position] = newValue;
    size++; // Increase the size of the array

    // Display the modified array
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

