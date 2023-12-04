// To find the Minimum Cost Spanning Tree of a graph

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

    // Read the Adjacency matrix
    int A[n][n], u, v;
    int min = INT_MAX;
    int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes, assign a big value to it to ignore it
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;
            // Note the minimum value - edge with lowest cost to start with
            if (A[i][j] < min) {
                min = A[i][j];
                u = i;
                v = j;
            }
        }
    }
    
    int e = 1;
    V[u] = 1;
    V[v] = 1;
    cost += min;
    printf("{%d, %d} = %d\n", u, v, min);

    // Repeat for each edge in the MST:
    while (e < n - 1) {
        min = INT_MAX;
        // For each row in the matrix
        for (int i = 0; i < n; i++) {
            // For each column in that row
            for (int j = 0; j < n; j++) {
                // Only checking for rows representing visited nodes, i.e. nodes adjascent to visited nodes
                if (V[i] == 1) {
                    // If the cost is less than minimum
                    if (A[i][j] < min) {
                        // If the node with the minimum cost is not already visited
                        if (V[j] != 1) {
                            // Update the minimum
                            min = A[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        // Mark the newly added minimum node as visited and print the edge of the spanning tree
        V[v] = 1;
        printf("{%d, %d} = %d\n", u, v, min);
        cost += min;
		e++;
    }
    printf("Minimum Cost: %d\n", cost);
}
