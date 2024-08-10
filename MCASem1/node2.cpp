#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct node {
    int key;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to perform inorder traversal of BST
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) return root;

    // Search for the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function
int main() {
    struct node* root = NULL;
    root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    int keyToDelete = 20; // Key to delete
    root = deleteNode(root, keyToDelete);

    printf("Inorder traversal after deletion of %d: ", keyToDelete);
    inorder(root);
    printf("\n");

    return 0;
}
