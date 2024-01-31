#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100

void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int V[MAX_NODES] = {0};

    // Read the Adjacency matrix
    int A[n][n];
    printf("Enter the Adjacency Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes, assign a big value to it to ignore it
            if (!A[i][j])
                A[i][j] = INT_MAX;
        }
    }
    
    int e = 0;
    int cost = 0;
    V[0] = 1;
    // For each edge in the spanning tree
    while (e < n - 1) {
        int min, u, v;
        // For each visited node in the graph
        for (int i = 0; i < n; i++) {
            if (V[i]) {
                // Find the smallest edge from the visited node to an unvisited node
                min = INT_MAX;
                for (int j = 0; j < n; j++) {
                    if (A[i][j] < min && !V[j]) {
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        // Mark the end of the minimum node as visited and print the edge
        V[v] = 1;
        printf("{%d, %d} = %d\n", u, v, min);
        cost += min;
		e++;
    }
    printf("Minimum Cost: %d\n", cost);
}
