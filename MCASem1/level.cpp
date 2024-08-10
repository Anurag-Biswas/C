#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
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

// Function to insert a node into the binary tree
void insertNode(struct Node** root, int value) {
    struct Node* newNode = createNode(value);
    
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* current = *root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the binary tree
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 70);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 60);
    insertNode(&root, 80);

    // Displaying the binary tree level-wise
    printf("Level Order Traversal: ");
    displayLevelOrder(root);

    return 0;
}
