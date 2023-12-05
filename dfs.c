#include <stdio.h>

#define MAX_NODES 100


void DFS(int graph[MAX_NODES][MAX_NODES], int n, int visited[], int source) {
    printf("%d ", source);
    visited[source] = 1;
    // For each node adjacent to u
    for (int i = 0; i < n; i++) {
        if (graph[source][i] != 0) {
            // If the node is not already visited
            if (visited[i] == 0)
                DFS(graph, n, visited, i);
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Visited Array
    int V[n];
    for (int i = 0; i < n; i++) {
        V[i] = 0;
    }

    // Adjacency matrix
    int A[n][n];
    int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // DFS 
    // (A Stack works in the background of the recursive algorithm)
    int source;
    printf("Enter the starting node: ");
    scanf("%d", &source);
    if (source < 0 || source >= n) {
        printf("Invalid!\n");
        return;
    }
    printf("DFS -> ");
    DFS(A, n, V, source);
    printf("\n");
}
