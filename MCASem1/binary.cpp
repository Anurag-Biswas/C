#include <stdio.h>
#include <math.h>

int main() {
    int binary[32]; // Assuming a 32-bit binary number
    int n, decimal = 0;

    // Input the binary number
    printf("Enter a binary number (up to 32 bits): ");
    scanf("%d", &n);

    // Convert the binary number to an array of digits
    for (int i = 0; i < 32; i++) {
        binary[i] = n % 10;
        n /= 10;
    }

    // Convert binary to decimal
    for (int i = 0; i < 32; i++) {
        decimal += binary[i] * pow(2, i);
    }

    printf("The decimal equivalent is: %d\n", decimal);

    return 0;
}
