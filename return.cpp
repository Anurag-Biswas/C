#include <stdio.h>

// Function to add two integers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two integers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two integers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to divide two integers
float divide(int num1, int num2) {
    if (num2 != 0) {
        return (float)num1 / num2;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0.0;
    }
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    int sum = add(num1, num2);
    int difference = subtract(num1, num2);
    int product = multiply(num1, num2);
    float quotient = divide(num1, num2);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %f\n", quotient);

    return 0;
}
