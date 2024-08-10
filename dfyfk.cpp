#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversedStr[100];
    int i, j;

    printf("Enter a string: ");
    gets(str);

    // Calculate the length of the string
    int length = strlen(str);

    // Reverse the string
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        reversedStr[j] = str[i];
    }
    reversedStr[j] = '\0'; // Null-terminate the reversed string

    // Print the reversed string
    printf("Reversed string: %s\n", reversedStr);

    return 0;
}
