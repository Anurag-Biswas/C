#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function prototypes
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
void display(struct Stack* stack);

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to insert an element into the stack (Push Operation)
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("%d pushed into the stack.\n", value);
}

// Function to delete an element from the stack (Pop Operation)
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Returning -1 to indicate an empty stack
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedValue;
}

// Function to return the value of the topmost element without deleting it
int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1; // Returning -1 to indicate an empty stack
    }

    return stack->top->data;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    struct Node* current = stack->top;

    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("%d popped from the stack.\n", value);
                }
                break;

            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;

            case 4:
                display(&stack);
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
