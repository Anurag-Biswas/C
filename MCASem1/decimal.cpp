#include <stdio.h>

// Function to convert decimal to binary and store in an array
void decimalToBinary(int decimal, int binaryArray[], int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        binaryArray[i] = decimal % 2;
        decimal /= 2;
    }
}

int main() {
    int decimalNumber;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0) {
        printf("Negative numbers are not supported.\n");
        return 1;
    }

    // Determine the number of bits required to represent the decimal number
    int numBits = 0;
    int temp = decimalNumber;
    while (temp > 0) {
        numBits++;
        temp /= 2;
    }

    if (numBits == 0) {
        numBits = 1; // Special case for decimal 0
    }

    int binaryArray[numBits];

    decimalToBinary(decimalNumber, binaryArray, numBits);

    printf("Binary representation: ");
    for (int i = 0; i < numBits; i++) {
        printf("%d", binaryArray[i]);
    }
    printf("\n");

    return 0;
}
