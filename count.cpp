#include<stdio.h>
#include<stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Count the number of leaf nodes
    int leafCount = countLeafNodes(root);

    printf("Number of leaf nodes in the binary tree: %d\n", leafCount);

    return 0;
}
