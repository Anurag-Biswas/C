#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
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

// Function to insert a new node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

// Function to search for an element in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Function to display the result of search operation
void displaySearchResult(struct Node* result, int key) {
    if (result == NULL)
        printf("%d not found in the BST.\n", key);
    else
        printf("%d found in the BST.\n", key);
}

int main() {
    struct Node* root = NULL;
    int elements[] = { 50, 30, 70, 20, 40, 60, 80 };
    int searchKeys[] = { 50, 90, 30, 10 };

    // Construct the BST
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++)
        root = insert(root, elements[i]);

    // Perform search operation and display results
    for (int i = 0; i < sizeof(searchKeys) / sizeof(searchKeys[0]); i++) {
        struct Node* result = search(root, searchKeys[i]);
        displaySearchResult(result, searchKeys[i]);
    }

    return 0;
}
