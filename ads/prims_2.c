#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int V[MAX_NODES] = {0};

    // Read the Adjacency matrix
    // int A[n][n];
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("A[%d][%d]: ", i, j);
    //         scanf("%d", &A[i][j]);
    //         // If there is no edge between two nodes, assign a big value to it to ignore it
    //         if (A[i][j] == 0)
    //             A[i][j] = INT_MAX;
    //     }
    // }
    // int A[4][4] = {{INT_MAX,5,2,7},{5,INT_MAX,1,INT_MAX},{2,1,INT_MAX,4},{7,INT_MAX,4,INT_MAX}};
    int A[4][4] = {{INT_MAX,2,INT_MAX,INT_MAX},{INT_MAX,INT_MAX,4,INT_MAX},{5,INT_MAX,INT_MAX,INT_MAX},{INT_MAX,INT_MAX,3,INT_MAX}};

    int e = 1;
    int cost = 0;
    V[0] = 1;
    // From all visited vertices, choose the edge with minimum weight and add it to the mst
    while (e < n) {
        int min = INT_MAX, u, v;
        // For each visited node in the graph
        for (int i = 0; i < n; i++) {
            if (V[i]) {
                // Find the smallest edge from that node, not already in the spanning tree
                for (int j = 0; j < n; j++) {
                    if (A[i][j] < min && !V[j]) {
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (min != INT_MAX) {
            V[v] = 1;
            printf("{%d, %d} = %d\n", u, v, min);
            cost += min;
            e++;
        }
    }
    printf("Minimum Cost: %d\n", cost);
}
