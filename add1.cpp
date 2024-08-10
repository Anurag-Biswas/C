#include <stdio.h>

int main() {
    int num1, num2, sum;
    int *ptr1, *ptr2;

    // Initialize num1 and num2 with user input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Initialize pointers to point to num1 and num2
    ptr1 = &num1;
    ptr2 = &num2;

    // Calculate the sum using pointers
    sum = *ptr1 + *ptr2;

    // Display the result
    printf("Sum of %d and %d is %d\n", *ptr1, *ptr2, sum);

    return 0;
}
