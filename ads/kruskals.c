#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100


int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent);


void main() 
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Read the Adjacency matrix, also creating flattened versions of it for sorting
    int n2 = n * n;
    int A[MAX_NODES][MAX_NODES], beforeSort[n2], sorted[n2];
    int cost = 0;
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes, assign a big value to it
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;

            // Insert the value in the 1D arrays
            beforeSort[(n * i) + j] = sorted[(n * i) + j] = A[i][j];
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


    // Construct the MST
    printf("The edges in the Minimum Spanning Tree are: \n");
    int mst[MAX_NODES][MAX_NODES] = {0};
    int edge_count = 0;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            // Finding where each value in the sorted array was, in the adjacency matrix
            if (sorted[i] == beforeSort[j]) {
                int row = j / n;
                int col = j % n;
                
                // Check if the edge exists
                if (A[row][col] == INT_MAX) {
                    mst[row][col] = 0;
                    break;
                }

                // Inserting into the MST
                mst[row][col] = sorted[i];

                // Marking the flat array to ignore this cost for further iterations
                beforeSort[j] = INT_MAX;

                // CHECKING FOR CYCLES (1)
                int isCyclic = 0;
                for (int k = 0; k < n; k++) {
                    int V[MAX_NODES] = {0};
                    int parents[MAX_NODES] = {0};
                    if (DFS(k, n, mst, V, parents, -1)) {
                        mst[row][col] = 0;
                        isCyclic = 1;
                        break;
                    }
                }
                if (isCyclic)
                    break;

                // Print each unique edge inserted and increment the cost (2)
                if (!mst[col][row]) {
                    cost += mst[row][col];
                    printf("{%d, %d} = %d\n", row, col, mst[row][col]);
                    edge_count++;

                    // If n - 1 edges are added, the mst is complete
                    if (edge_count == n - 1) {
                        printf("Minimum Cost: %d\n", cost);
                        return;
                    }
                }
            }
        }
    }
    printf("Minimum Cost: %d\n", cost);
}


// DFS Function: To detect Cycle in a Graph
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent) {
    if (!visited[node]) {
        visited[node] = 1;
        // recStack is used to keep track of nodes in the current path of traversal
        recStack[node] = 1;

        for (int i = 0; i < n; i++) {
            if (graph[node][i] != 0) {
                // Recursively calling the function on each unvisited node
                if (!visited[i] && DFS(i, n, graph, visited, recStack, node)) {
                    return 1;
                // If the node is already visited, and the node is not the parent of the current node (2)
                } else if (recStack[i] && i != parent) {
                    return 1;
                }
            }
        }
    }
    // Remove the node from the recursion stack
    recStack[node] = 0;
    return 0;
}


// (1) We perform DFS from every vertex, since the graph may not be connected
// (2) For undirected graphs, edge {a, b} is the same as {b, a}, hence if we are on b, and see that a is already visited,
//     this does not imply that a -> b -> a is a cycle.
