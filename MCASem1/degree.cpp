#include <stdio.h>

#define MAX_NODES 100

// Function to calculate the degree of a given node in a graph
int calculateDegree(int node, int graph[MAX_NODES][MAX_NODES], int numNodes) {
    int degree = 0;

    // Iterate through the row corresponding to the given node in the adjacency matrix
    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] == 1) {
            degree++;
        }
    }

    return degree;
}

int main() {
    int numNodes;
    
    // Get the number of nodes in the graph
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0 || numNodes > MAX_NODES) {
        printf("Invalid number of nodes. Please enter a value between 1 and %d.\n", MAX_NODES);
        return 1;
    }

    int graph[MAX_NODES][MAX_NODES];

    // Get the adjacency matrix representing the graph
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int node;

    // Get the node for which you want to calculate the degree
    printf("Enter the node for which you want to calculate the degree: ");
    scanf("%d", &node);

    if (node < 0 || node >= numNodes) {
        printf("Invalid node. Please enter a node index between 0 and %d.\n", numNodes - 1);
        return 1;
    }

    // Calculate and print the degree of the given node
    int degree = calculateDegree(node, graph, numNodes);
    printf("The degree of node %d is: %d\n", node, degree);

    return 0;
}
