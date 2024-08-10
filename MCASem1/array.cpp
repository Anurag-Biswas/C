#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Structure to represent a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree using array representation
void insertNode(struct TreeNode* treeArray[], int index, int data) {
    struct TreeNode* newNode = createNode(data);
    treeArray[index] = newNode;
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct TreeNode* root, int size) {
    if (root == NULL)
        return;

    for (int i = 0; i < size; i++) {
        if (treeArray[i] != NULL)
            printf("%d ", treeArray[i]->data);
        else
            printf("- ");

        if (i % 2 == 0)
            printf("| ");
    }
}

int main() {
    int size, data;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &size);

    // Create an array to store the binary tree nodes
    struct TreeNode* treeArray[MAX_SIZE];

    // Input the data for each node and insert it into the array
    for (int i = 0; i < size; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(treeArray, i, data);
    }

    // Display the binary tree level-wise
    printf("\nBinary Tree Level-wise:\n");
    displayLevelOrder(treeArray[0], size);

    return 0;
}
