#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void main() 
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Read the Adjacency matrix, also creating a flattened version of the 2D array for sorting
    int A[n][n], u, v;
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

    // Visited Array
    int V[n];
    for (int i = 0; i < n; i++) {
        V[i] = 0;
    }

    // DFS Function
    void DFS(int u, int A[n][n]) {
        V[u] = 1;
        for (int i = 0; i < n; i++) {
            if (A[u][i] != INT_MAX && V[i] != 1) {
                DFS(i, A);
            }
        }
    };

    // MST
    int mst[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mst[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            // Finding where each value in the sorted array was, in the adjacency matrix
            if (sorted[i] == toSort[j]) {
                int row = j / n;
                int col = j % n;
                mst[row][col] = sorted[j];
                mst[col][row] = sorted[i];
                // if (A[row][col] != INT_MAX)
                //     printf("{%d, %d} = %d\n", row, col, A[row][col]);
                toSort[j] = INT_MAX;
                break;
            }
        }
        // Removing cycles from the mst
        for (int k = 0; k < n; k++) {
            V[k] = 0;
        }
        DFS(0, mst);
        int cycle = 0;
        for (int k = 0; k < n; k++) {
            if (V[k] == 0) {
                cycle = 1;
                break;
            }
        }
        if (cycle) {
            int row = (i + 1) / n;
            int col = (i + 1) % n;
            mst[row][col] = INT_MAX;
            mst[col][row] = INT_MAX;
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mst[i][j] == INT_MAX) {
                printf("0 ");
                continue;
            }
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }
}

