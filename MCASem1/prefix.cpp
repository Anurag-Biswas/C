#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return the precedence of an operator
int getPrecedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;  // Default precedence
}

// Function to convert infix expression to prefix notation
void infixToPrefix(char infix[], char prefix[]) {
    int i, j, len = strlen(infix);
    char stack[len], postfix[len];
    int top = -1, ptop = -1;

    // Reverse the infix expression
    for (i = len - 1; i >= 0; i--) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Convert infix to postfix
    for (i = 0, j = 0; i < len; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  // Pop the opening parenthesis
        } else if (isOperator(c)) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    // Reverse the postfix expression to get the prefix expression
    for (i = j - 1; i >= 0; i--) {
        prefix[++ptop] = postfix[i];
    }
    prefix[j] = '\0';
}

int main() {
    char infix[100], prefix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Infix Expression: %s\n", infix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
