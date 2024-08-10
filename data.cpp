#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with a given key in BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return createNode(key);

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    // Return the unchanged node pointer
    return root;
}

// Function to perform inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Displaying the original BST
    printf("Original BST: ");
    inorder(root);
    printf("\n");

    // Inserting a specific element (e.g., 45) into the BST
    int elementToInsert = 45;
    root = insert(root, elementToInsert);

    // Displaying the modified BST after inserting the element
    printf("BST after inserting %d: ", elementToInsert);
    inorder(root);
    printf("\n");

    return 0;
}
