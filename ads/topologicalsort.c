#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100


int indegree(int graph[][MAX_NODES], int n, int node);


void main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Adjacency matrix
    int A[MAX_NODES][MAX_NODES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Visited Array
    int V[n];
    memset(V, 0, sizeof(V));

    // Topological Sorting
    int count = 0;
    while (count < n) {
        for (int i = 0; i < n; i++) {
            // If the indegree of an unvisited node is 0
            if (indegree(A, n, i) == 0 && !V[i]) {
                printf("%d\n", i);
                V[i] = 1;
                // Remove the row corresponding to this node by setting it to 0
                for (int j = 0; j < n; j++) 
                    A[i][j] = 0;
                break;
            }
        }
        count++;
    }
}


// Indegree: Sum of the column in the matrix corresponding to that node
int indegree(int graph[][MAX_NODES], int n, int node) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += graph[i][node];
    return sum;
}