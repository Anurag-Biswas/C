#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count internal nodes in a binary tree
int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0; // Base case: empty tree or leaf node
    }

    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Example usage
int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Count and display the number of internal nodes
    int internalNodeCount = countInternalNodes(root);
    printf("Number of internal nodes in the binary tree: %d\n", internalNodeCount);

    return 0;
}
