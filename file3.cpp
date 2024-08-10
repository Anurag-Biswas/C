#include <stdio.h>

int main() {
    char filename[100];

    printf("Enter the name of the file to delete: ");
    scanf("%s", filename);

    // Attempt to delete the file
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        printf("Unable to delete file '%s'. Check if the file exists or if you have the necessary permissions.\n", filename);
    }

    return 0;
}
