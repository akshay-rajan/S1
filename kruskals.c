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
    int min = INT_MAX;
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
    // Find the edge corresponding to a value in sorted by finding it in toSort and decoding its previous position    

}

