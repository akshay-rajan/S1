#include <stdio.h>

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

    // Perform DFS starting from a node 'u' 
    // (A Stack works in the background of the recursive algorithm)
    void dfs(int u) {
        printf("%d ", u);
        V[u] = 1;
        // For each node adjacent to u
        for (int i = 0; i < n; i++) {
            if (A[u][i] != 0) {
                // If the node is not already visited, perform DFS on it
                if (V[i] == 0)
                    dfs(i);
            }
        }
    }

    printf("Performing DFS starting from the first vertex: \n");
    dfs(0);
    printf("\n");
}
