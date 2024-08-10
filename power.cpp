#include <stdio.h>

// Function to calculate the power of a number using recursion
double power(double base, int exponent) {
    // Base case: If the exponent is 0, return 1
    if (exponent == 0) {
        return 1;
    }
    // Recursive case: Calculate power using recursion
    else {
        if (exponent > 0) {
            return base * power(base, exponent - 1);
        } else {
            // If the exponent is negative, calculate the reciprocal
            return 1.0 / (base * power(base, -exponent - 1));
        }
    }
}

int main() {
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);

    printf("%.2lf^%d = %.2lf\n", base, exponent, result);

    return 0;
}
