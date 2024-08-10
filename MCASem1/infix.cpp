#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure and operations
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    int i, j,isalum;
    struct Stack* stack = createStack(MAX_SIZE);
    char postfix[MAX_SIZE];

    for (i = 0, j = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Remove the '('
        } else {
            while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, c);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}

