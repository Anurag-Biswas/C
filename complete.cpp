#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int n;

int isComplete() {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // If there is an edge and it's not the diagonal (self-loop)
            // or if there's no edge and it's not the diagonal, then the
            // graph is not complete
            if ((adj[i][j] && i != j && adj[j][i] == 0) || (!adj[i][j] && i != j && adj[j][i] == 1))
                return 0;
        }
    }

    return 1; // Graph is complete
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (isComplete())
        printf("The given graph is complete.\n");
    else
        printf("The given graph is not complete.\n");

    return 0;
}
