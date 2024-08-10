#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for an element in the binary search tree recursively
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to traverse and print the binary search tree in inorder
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int elements[] = { 50, 30, 20, 40, 70, 60, 80 };
    int n = sizeof(elements) / sizeof(elements[0]);

    // Insert elements into the binary search tree
    for (int i = 0; i < n; i++) {
        root = insertNode(root, elements[i]);
    }

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    // Search for an element in the binary search tree
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("%d found in the binary search tree.\n", key);
    } else {
        printf("%d not found in the binary search tree.\n", key);
    }

    return 0;
}
