#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100


// DFS function for both graphs
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent) {
    if (visited[node] == 0) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int i = 0; i < n; ++i) {
            if (graph[node][i] != 0) {
                if (!visited[i] && DFS(i, n, graph, visited, recStack, node)) {
                    return 1; // Cycle detected
                } else if (recStack[i] && i != parent) {
                    return 1; // Back edge detected, indicating a cycle
                }
            }
        }
    }
    recStack[node] = 0; // Remove the node from the recursion stack
    return 0; // No cycle detected
}


int main() {
    // Example graph (adjacency matrix)
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 0, 2, 7},
        {0, 0, 1, 0},
        {2, 1, 0, 4},
        {0, 0, 4, 0}
    };
    int graph2[MAX_NODES][MAX_NODES] = {
        {0, 5, 2, 7},
        {5, 0, 1, 0},
        {2, 1, 0, 4},
        {7, 0, 4, 0}
    };

    int n = 4; // Number of nodes

    int visited[MAX_NODES] = {0}; // Initialize visited array
     int recStack[MAX_NODES] = {0}; // Initialize recursion stack

    if (DFS(0, n, graph, visited, recStack, -1)) {
        printf("Cycle detected!\n");
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}
