#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Checking and removing duplicates
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;) {
            if (arr[i] == arr[j]) {
                // Shift elements to the left to overwrite duplicates
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // Reduce array size
            } else {
                j++;
            }
        }
    }

    printf("Array with duplicates removed: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
