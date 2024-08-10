
int main() {
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from the input
    inputString[strcspn(inputString, "\n")] = '\0';

    int length = strlen(inputString);

    printf("Reverse of the string: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", inputString[i]);
    }
    printf("\n");

    return 0;
}
