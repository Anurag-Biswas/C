#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr; // Initialize a pointer to the first element of the array
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += *ptr; // Add the value pointed to by ptr to the sum
        ptr++;       // Move the pointer to the next element
    }

    printf("Sum of array elements: %d\n", sum);
    return 0;
}
