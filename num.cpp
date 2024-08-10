#include <stdio.h>

int sumOfDigits(int num) {
    // Base case: If the number is a single digit, return the number itself.
    if (num < 10) {
        return num;
    } else {
        // Recursively calculate the sum of digits of the number.
        return num % 10 + sumOfDigits(num / 10);
    }
}

int main() {
    int num, sum;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        sum = sumOfDigits(num);
        printf("The sum of digits of %d is %d.\n", num, sum);
    }

    return 0;
}
