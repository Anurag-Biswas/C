#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int lineCount = 0;

    // Prompt the user for the file name
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file exists and can be opened
    if (file == NULL) {
        printf("File not found or cannot be opened.\n");
        return 1; // Exit with an error code
    }

    // Read the file character by character and count lines
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    // Close the file
    fclose(file);

    // Print the line count
    printf("The file '%s' has %d lines.\n", filename, lineCount);

    return 0; // Exit successfully
}
