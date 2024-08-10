#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

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

// Function to free memory allocated to BST
void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    // Initialize the root of the BST
    struct Node* root = NULL;
    
    // Input the number of elements in the set
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input the elements and insert them into the BST
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        root = insert(root, num);
    }

    // Perform inorder traversal to get sorted order
    printf("Sorted order: ");
    inorder(root);
    printf("\n");
    
    // Free memory allocated to the BST
    freeBST(root);

    return 0;
}
