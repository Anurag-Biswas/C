#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    if (n < 2) {
        printf("At least two elements are required for finding the second highest.\n");
        return 1;
    }

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bubbleSort(arr, n);

    // The second highest number will be the second-to-last element
    int secondHighest = arr[n - 2];

    printf("The second highest number in the array is: %d\n", secondHighest);

    return 0;
}
