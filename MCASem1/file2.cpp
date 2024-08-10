#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("File not found or unable to open the file.\n");
        exit(1); // Exit the program
    }

    // Read and print the contents of the file character by character
    printf("Contents of the file:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return 0;
}
