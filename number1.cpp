#include <stdio.h>

#define MAX 10

int main() {
    int graph[MAX][MAX], vertices, edges;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    edges = 0;
    for (i = 0; i < vertices; i++) {
        for (j = i + 1; j < vertices; j++) {
            if (graph[i][j] == 1)
                edges++;
        }
    }

    printf("Number of vertices: %d\n", vertices);
    printf("Number of edges: %d\n", edges);

    return 0;
}
