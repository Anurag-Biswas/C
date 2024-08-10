#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void initializeGraph() {
    int i, j;
    numVertices = 6; // Number of vertices in the graph

    // Initialize the graph with zeros
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Define the connections between vertices (edges)
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[4][5] = 1;
}

void displayGraph() {
    int i, j;

    printf("Adjacency Matrix:\n");

    // Display the adjacency matrix
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();
    displayGraph();
    return 0;
}
