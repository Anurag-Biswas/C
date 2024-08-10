#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a node in the binary tree
struct Node {
    int data;
    int left;  // Index of the left child in the array
    int right; // Index of the right child in the array
};

// Function to count the number of nodes in the binary tree
int countNodes(struct Node tree[], int root) {
    if (root == -1) {
        return 0;
    } else {
        return 1 + countNodes(tree, tree[root].left) + countNodes(tree, tree[root].right);
    }
}

int main() {
    // Example binary tree represented using an array
    struct Node binaryTree[MAX_SIZE] = {
        {1, 1, 2},  // Root
        {2, 3, 4},  // Left child of node 1
        {3, 5, 6},  // Right child of node 1
        {4, -1, -1}, // Left child of node 2
        {5, -1, -1}, // Right child of node 2
        {6, -1, -1}  // Left child of node 3
    };

    // Root index is 0 in this example
    int rootIndex = 0;

    // Count the number of nodes in the binary tree
    int nodeCount = countNodes(binaryTree, rootIndex);

    printf("Number of nodes in the binary tree: %d\n", nodeCount);

    return 0;
}
