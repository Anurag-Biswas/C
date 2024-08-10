#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element, stack is full.\n");
    } else {
        top++;
        stack[top] = element;
        printf("Element %d pushed into the stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
    } else {
        printf("Element %d popped from the stack.\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Signifying an empty stack
    } else {
        return stack[top];
    }
}

int main() {
    int choice, element;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                element = peek();
                if (element != -1) {
                    printf("Topmost element is: %d\n", element);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
