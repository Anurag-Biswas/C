#include <stdio.h>

// Define a structure to store student information
struct Student {
    int rollNo;
    char name[50];
    char address[100];
    int age;
    float averageMarks;
};

// Function to read and display student details
void readAndDisplayStudentDetails(struct Student students[], int count) {
    printf("Enter the details of 12 students:\n");

    for (int i = 0; i < count; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Address: ");
        scanf("%s", students[i].address);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].averageMarks);
        printf("\n");
    }

    printf("Displaying student details:\n");

    for (int i = 0; i < count; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s\n", students[i].address);
        printf("Age: %d\n", students[i].age);
        printf("Average Marks: %.2f\n", students[i].averageMarks);
        printf("\n");
    }
}

int main() {
    // Define an array of structures to store 12 students
    struct Student students[12];

    // Call the function to read and display student details
    readAndDisplayStudentDetails(students, 12);

    return 0;
}
