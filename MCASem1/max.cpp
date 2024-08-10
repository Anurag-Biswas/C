#include <stdio.h>

// Function to find the maximum of two numbers
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the minimum of two numbers
int findMin(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int maximum = findMax(num1, num2);
    int minimum = findMin(num1, num2);

    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);

    return 0;
}
