#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    
    // Check if the string has at least 3 characters
    if (str[2]!='\0') {
        char thirdElement = str[2]; // Strings are 0-indexed, so the third element is at index 2
        printf("The 3rd element of the string is: %c\n", thirdElement);
    } else {
        printf("The string doesn't have at least 3 characters.\n");
    }

    return 0;
}
