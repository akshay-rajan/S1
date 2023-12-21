// Single Source Shortest Path Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Source Array: To keep track of nodes taken as the source
    int S[n];
    for (int i = 0; i < n; i++)
        S[i] = 0;

    // Distance Array: Distance from the source to each node
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

    // Djikstra's Algorithm

    int source;    
    printf("Enter the starting node: \n");
    scanf("%d", &source);
    if (source < 0 || source >= n) {
        printf("Invalid!\n");
        return;
    }

    // Update the distance of the source to 0
    distance[source] = 0;
    int source_count = 1;

    // For each node as the source
    while (source_count <= n) {
        // Mark the node as 'taken'
        S[source] = 1;
        // For each node adjacent to the source, update its distance
        for (int i = 0; i < n; i++) {
            if (A[source][i] != INT_MAX) {
                // Relaxation Formula: If d(u) + c(u, v) < d(v), then d(v) = d(u) + c(u, v)
                if (distance[source] + A[source][i] < distance[i])
                    distance[i] = distance[source] + A[source][i];
            }
        }
        // Pick the next source
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            // Minimum value in the distance array not already picked as source
            if (distance[i] < min && !S[i]) {
                min = distance[i];
                source = i;
            }
        }
        source_count++;
    }

    // Print the Distances
    printf("Node\t Distance\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d \n", i, distance[i]);
    }
}