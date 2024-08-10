#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
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

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        displayLevelOrder(root->left, level - 1);
        displayLevelOrder(root->right, level - 1);
    }
}

// Function to find the height of the binary tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to display the binary tree level-wise
void displayLevelOrderTraversal(struct Node* root) {
    int height = findHeight(root);
    for (int i = 1; i <= height; i++) {
        displayLevelOrder(root, i);
    }
}

// Driver program to test the functions
int main() {
    struct Node* root = NULL;

    // Inserting elements into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Displaying the binary tree level-wise
    printf("Level Order Traversal: ");
    displayLevelOrderTraversal(root);

    return 0;
}
