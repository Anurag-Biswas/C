#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Both strings are equal.\n");
    } else if (result < 0) {
        printf("First string is lexicographically smaller than the second string.\n");
    } else {
        printf("First string is lexicographically larger than the second string.\n");
    }

    return 0;
}
