#include <stdio.h>

// Define the structure
struct company {
    char name[100];
    char address[100];
    char phone[15];
    int noOfEmployee;
};

int main() {
    // Declare a variable of the company structure
    struct company myCompany;

    // Read company details from the user
    printf("Enter the name of the company: ");
    scanf("%99[^\n]s", myCompany.name); // Read up to 99 characters, leaving room for the null terminator
    getchar(); // Consume the newline character left in the input buffer

    printf("Enter the address of the company: ");
    scanf("%99[^\n]s", myCompany.address);
    getchar();

    printf("Enter the phone number of the company: ");
    scanf("%14s", myCompany.phone); // Read up to 14 characters (including a null terminator)
    getchar();

    printf("Enter the number of employees: ");
    scanf("%d", &myCompany.noOfEmployee);

    // Display the company details
    printf("\nCompany Details:\n");
    printf("Name: %s\n", myCompany.name);
    printf("Address: %s\n", myCompany.address);
    printf("Phone: %s\n", myCompany.phone);
    printf("Number of Employees: %d\n", myCompany.noOfEmployee);

    return 0;
}
