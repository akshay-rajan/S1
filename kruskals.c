#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[]);


void main() 
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Read the Adjacency matrix, also creating a flattened version of it for sorting
    int A[MAX_NODES][MAX_NODES], u, v;
    int n2 = n * n;
    int toSort[n2];
    int sorted[n2];
    int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes, assign a big value to it to ignore it
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;

            // Insert the value in the 1D array
            toSort[(n * i) + j] = A[i][j];
            sorted[(n * i) + j] = A[i][j];
        }
    }

    // Sort the flattened array: Bubble Sort
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2 - 1; j++) {
            if (sorted[j + 1] < sorted[j]) {
                int tmp = sorted[j + 1];
                sorted[j + 1] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }

    // Construct the MST, avoiding cycles (DFS)

    // MST
    int mst[MAX_NODES][MAX_NODES] = {0};
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            // Finding where each value in the sorted array was, in the adjacency matrix
            if (sorted[i] == toSort[j]) {
                int row = j / n;
                int col = j % n;
                
                // Check if the edge exist
                if (A[row][col] == INT_MAX) {
                    mst[row][col] = 0;
                    break;
                }
                mst[row][col] = sorted[i];

                // Make sure there are no cycles using DFS
                int V[MAX_NODES] = {0};
                int parents[MAX_NODES] = {0};

                if (DFS(row, n, mst, V, parents)) {
                    // Cycle found
                    printf("Cycle found at %d!\n", i);
                    mst[row][col] = 0;
                    break;

                }
                toSort[j] = INT_MAX;
                // -------------DEBUG----------------
                printf("\nInserted '%d' at mst[%d][%d]\n", mst[row][col], row, col);
                printf("Minimum Spanning Tree: \n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", mst[i][j]);
                    }
                    printf("\n");
                }
                printf("ToSort: ");
                for (int i = 0; i < n2; i++) {
                    if (toSort[i] == INT_MAX)
                        printf("~ ");
                    else
                        printf("%d ", toSort[i]);
                } 
                printf("\nSorted: ");
                for (int i = 0; i < n2; i++) {
                    if (sorted[i] == INT_MAX)
                        printf("~ ");
                    else
                        printf("%d ", sorted[i]);
                }
                // -------------DEBUG----------------
            }
        }
    }
    // Print the MST
    printf("Minimum Spanning Tree: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }
}

// DFS Function: To detect Cycle in a graph
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[]) {
    if (visited[node] == 0) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int i = 0; i < n; ++i) {
            if (graph[node][i] != 0) {
                if (!visited[i] && DFS(i, n, graph, visited, recStack)) {
                    return 1; // Cycle detected
                } else if (recStack[i]) {
                    return 1; // Back edge detected, indicating a cycle
                }
            }
        }
    }
    recStack[node] = 0; // Remove the node from the recursion stack
    return 0; // No cycle detected
}