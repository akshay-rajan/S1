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

    // Read the Adjacency matrix
    int A[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes
            if (!A[i][j])
                A[i][j] = INT_MAX;
        }
    }

    int mst[MAX_NODES][MAX_NODES] = {0};
    int edge_count = 0, cost = 0;
    printf("The edges in the Minimum Spanning Tree are: \n");
    while (edge_count < n - 1) {
        // Find the smallest edge
        int min = INT_MAX, u, v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] < min) {
                    min = A[i][j];
                    u = i, v = j;
                }
            }
        }

        // Add the smallest edge to the MST and remove it from the graph
        mst[u][v] = min;
        A[u][v] = INT_MAX;
        
        // If the added edge forms a cycle in the MST, remove it 
        for (int i = 0; i < n; i++) {
            int visited[MAX_NODES] = {0}, recStack[MAX_NODES] = {0};
            if (DFS(i, n, mst, visited, recStack, -1)) {
                mst[u][v] = 0;
                break;
            }
        }

        // Print each unique edge ({a, b} is unique if {b, a} is not already present)
        if (!mst[v][u] && mst[u][v] != 0) {
            cost += min;
            printf("{%d, %d} = %d\n", u, v, mst[u][v]);
            edge_count++;
        }
    }
    printf("Minimum Cost: %d\n", cost);
}


// DFS Function: To detect Cycle in a Graph
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent) {
    if (!visited[node]) {
        // recStack is used to keep track of nodes in the current path of traversal
        visited[node] = recStack[node] = 1;

        for (int i = 0; i < n; i++) {
            if (graph[node][i] != 0) {
                // Recursively calling the function on each unvisited node
                if (!visited[i])
                     DFS(i, n, graph, visited, recStack, node);
                // If the node is already visited, and the node is not the parent of the current node (2)
                else if (recStack[i] && i != parent)
                    return 1;
            }
        }
    }
    // Remove the node from the recursion stack
    recStack[node] = 0;
    return 0;
}
