#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent adjacency list
struct List {
    struct Node* head;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct List* array;
};

// Function to create a new node
struct Node* newNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = (struct List*)malloc(numVertices * sizeof(struct List));

    for (int i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode1 = newNode(dest);
    newNode1->next = graph->array[src].head;
    graph->array[src].head = newNode1;

    // Add an edge from dest to src
    struct Node* newNode2 = newNode(src);
    newNode2->next = graph->array[dest].head;
    graph->array[dest].head = newNode2;
}

// Utility function to detect cycle using DFS
int isCyclicUtil(struct Graph* graph, int v, int visited[], int parent) {
    visited[v] = 1; // Mark the current node as visited

    // Recur for all the vertices adjacent to this vertex
    struct Node* currentNode = graph->array[v].head;
    while (currentNode != NULL) {
        int dest = currentNode->dest;

        // If an adjacent is not visited, then recur for it
        if (!visited[dest]) {
            if (isCyclicUtil(graph, dest, visited, v))
                return 1;
        }

        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (dest != parent)
            return 1;

        currentNode = currentNode->next;
    }
    return 0;
}

// Function to detect cycle in the graph
int isCyclic(struct Graph* graph) {
    // Mark all the vertices as not visited and not part of recursion stack
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i)
        visited[i] = 0;

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int u = 0; u < graph->numVertices; u++)
        if (!visited[u])
            if (isCyclicUtil(graph, u, visited, -1))
                return 1;

    return 0;
}

// Main function
int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    if (isCyclic(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    return 0;
}
