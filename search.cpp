#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sample array
    int n = sizeof(array) / sizeof(array[0]); // Calculate the number of elements in the array
    int target;
    int found = 0; // Flag to indicate if the element is found

    printf("Enter the element you want to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        if (array[i] == target) {
            printf("Element %d found at index %d\n", target, i);
            found = 1;
            break; // Element found, no need to continue searching
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
