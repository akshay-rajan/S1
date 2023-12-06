// Single Source Shortest Path Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Source Array
    int V[n];
    for (int i = 0; i < n; i++)
        V[i] = 0;

    // Distance Array
    int distance[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
    }
    
    // Adjacency matrix
    int A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;
        }
    }

    
    // Start with node 0 as source
    int source = 0;    

    // Update the distance of this node to 0
    distance[source] = 0;

    int source_count = 1;

    // Update the distance of all nodes adjacent to this node based on the relaxation formula
    while (source_count < n) {
        V[source] = 1;
        for (int i = 0; i < n; i++) {
            if (A[source][i] != INT_MAX) {
                // Relaxation Formula: If d(u) + c(u, v) < d(v), then d(v) = d(u) + c(u, v)
                if (distance[source] + A[source][i] < distance[i])
                    distance[i] = distance[source] + A[source][i];
                    printf("distance[%d]: %d\n", i, distance[i]);
            }
        }
        // PICK THE NEXT SOURCE: Next minimum in the distance array not picked as source
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (distance[i] < min) {
                min = distance[i];
                source = i;
            }
        }
        source_count++;
    }

    // Print the Distance Array
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX)
            printf("%d: ~ ", i);
        else
            printf("%d: %d ", i, distance[i]);
    }
    printf("\n");
}