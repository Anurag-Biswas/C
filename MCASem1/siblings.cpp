#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count the number of siblings
int countSiblings(struct TreeNode* root, int targetValue) {
    if (root == NULL) {
        return 0;
    }

    // Check left and right children for siblings
    if (root->left != NULL && root->right != NULL) {
        if ((root->left->data == targetValue && root->right->data != targetValue) ||
            (root->left->data != targetValue && root->right->data == targetValue)) {
            return 1 + countSiblings(root->left, targetValue) + countSiblings(root->right, targetValue);
        }
    }

    // Continue searching in the left and right subtrees
    return countSiblings(root->left, targetValue) + countSiblings(root->right, targetValue);
}

int main() {
    // Sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int targetValue = 5;
    int siblingsCount = countSiblings(root, targetValue);

    printf("Number of siblings for node with value %d: %d\n", targetValue, siblingsCount);

    return 0;
}
