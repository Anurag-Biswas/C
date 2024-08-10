#include <stdio.h>

// Define a structure to store employee details
struct Employee {
    char name[50];
    int employeeID;
    float salary;
};

int main() {
    // Declare a variable of the Employee structure
    struct Employee emp;

    // Input employee details
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter Employee ID: ");
    scanf("%d", &emp.employeeID);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Print employee details
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Employee ID: %d\n", emp.employeeID);
    printf("Salary: $%.2f\n", emp.salary);

    return 0;
}
