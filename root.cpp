#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the BST
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a character into the BST
struct Node* insert(struct Node* root, char data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to perform in-order traversal of BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

int main() {
    char name[100];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Removing the newline character from fgets input

    struct Node* root = NULL;

    // Inserting characters of the name into BST
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] != ' ') // Ignore spaces
            root = insert(root, name[i]);
    }

    // Printing the sorted sequence of characters
    printf("Sorted sequence of characters in your name: ");
    inOrder(root);

    return 0;
}
