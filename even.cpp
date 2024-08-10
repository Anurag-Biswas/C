#include <stdio.h>

// Function to check if a number is even or odd
int isEvenOrOdd(int num) {
    if (num % 2 == 0) {
        return 1; // Even
    } else {
        return 0; // Odd
    }
}

int main() {
    int number;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Check if the number is even or odd using the function
    if (isEvenOrOdd(number)) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }

    return 0;
}

