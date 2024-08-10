#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

// Function to count the number of nodes in BST
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the highest element in BST
int findHighest(struct TreeNode* root) {
    if (root == NULL) {
        printf("The BST is empty.\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->val;
}

int main() {
    // Creating a sample BST
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Counting nodes
    int nodeCount = countNodes(root);
    printf("Number of nodes in the BST: %d\n", nodeCount);

    // Finding the highest element
    int highest = findHighest(root);
    if (highest != -1)
        printf("Highest element in the BST: %d\n", highest);

    return 0;
}
