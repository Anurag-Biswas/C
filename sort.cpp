#include <stdio.h>

int main() {
    int n;
    
    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Check if there are at least two elements in the array
    if (n < 2) {
        printf("At least two elements are required to find the second highest.\n");
        return 1; // Exit with an error code
    }

    int arr[n];

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int firstMax, secondMax;

    if (arr[0] > arr[1]) {
        firstMax = arr[0];
        secondMax = arr[1];
    } else {
        firstMax = arr[1];
        secondMax = arr[0];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax && arr[i] < firstMax) {
            secondMax = arr[i];
        }
    }

    printf("The second highest number is: %d\n", secondMax);

    return 0;
}
