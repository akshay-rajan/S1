#include <stdio.h>
#include <stdlib.h>

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
    int A[n][n];
    int min = 999;
    int u, v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes, assign a big value to it to ignore it
            if (A[i][j] == 0)
                A[i][j] = 999;
            // Note the minimum value
            if (A[i][j] < min) {
                u = i;
                v = j;
            }
        }
    }
    
    int cost = 0;
    int e = 1;
    V[u] = 1;
    V[v] = 1;
    cost += A[u][v];
    printf("{%d, %d} = %d\n", u, v, min);

    // Repeat for each edge in the MST
    while (e < n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                min = 999;
                // Check if the node i is visited
                if (V[i] == 1) {
                    if (A[i][j] < min) {
                        // If the node j is not visited
                        if (V[j] != 1) {
                            min = A[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        printf("{%d, %d} = %d\n", u, v, min);
        cost += min;
		e++;
    }
    printf("Minimum Cost: %d\n", cost);
}
