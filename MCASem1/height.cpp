#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the height of a binary tree
int findHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        // Return the maximum of left and right subtree heights, plus 1 for the current level
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int main() {
    // Example usage
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height of the binary tree is: %d\n", findHeight(root));

    // Free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
