#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100


int isTraversed(int array[], int n);
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent);


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

            // Insert the value in the 1D arrays
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

    int visitedArray[MAX_NODES] = {0};

    // Construct the MST
    printf("The edges in the MST are: \n");
    int mst[MAX_NODES][MAX_NODES] = {0};
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            // Finding where each value in the sorted array was, in the adjacency matrix
            if (sorted[i] == toSort[j]) {
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
                toSort[j] = INT_MAX;

                // ----------------------CHECKING FOR CYCLES--------------------------
                // Perform DFS from every vertex, since the graph may not be connected
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

                // For each unique edge inserted**
                if (!mst[col][row]) {
                    visitedArray[row] = visitedArray[col] = 1;
                    cost += mst[row][col];
                    printf("{%d, %d} = %d\n", row, col, mst[row][col]);
                }

                // If the construction of the MST is complete---NEED LOGIC TO MAKE SURE THE GRAPH IS CONNECTED BEFORE EXITING
                if (isTraversed(visitedArray, n)) {
                    // Print the MST and Minimum Cost
                    printf("Minimum Spanning Tree: \n");
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            printf("%d ", mst[i][j]);
                        }
                        printf("\n");
                    }
                    printf("Minimum Cost: %d\n", cost);
                    return;
                }
            }
        }
    }
}


// Check if all elements in an array is set to 1
int isTraversed(int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == 0)
            return 0;
    }
    return 1;
}


// DFS Function: To detect Cycle in a Graph
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent) {
    if (visited[node] == 0) {
        visited[node] = 1;
        // recStack is used to keep track of nodes in the current path of searching
        recStack[node] = 1;

        for (int i = 0; i < n; ++i) {
            if (graph[node][i] != 0) {
                // Recursively calling the function on each unvisited node
                if (!visited[i] && DFS(i, n, graph, visited, recStack, node)) {
                    return 1;
                // If the node is already visited, and the node is not the parent of the current node**
                } else if (recStack[i] && i != parent) {
                    return 1;
                }
            }
        }
    }
    // Remove the node from the recursion stack
    recStack[node] = 0;
    // No cycle detected
    return 0;
}

// ** For undirected graphs, edge {a, b} is the same as {b, a}, hence if we are on b, and see that a is already visited,
// this does not imply that a -> b -> a is a cycle.

