#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int n;
int queue[MAX_NODES];
int front = -1, rear = -1;


void enqueue(int value);
int dequeue();


void BFS(int graph[][MAX_NODES], int n, int visited[], int source) {
    enqueue(source);
    visited[source] = 1;
    
    // Repeat until the queue is empty
    while (front <= rear) {
        // Perform dequeue and print the removed node
        int node = dequeue();
        printf("%d ", node);
        // For all adjacent nodes of the deleted node that are unvisited
        for (int i = 0; i < n; i++) {
            if (graph[node][i] != 0 && !visited[i]) {
                // Enqueue it and mark it as visited
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Visited Array
    int V[n];
    for (int i = 0; i < n; i++) {
        V[i] = 0;
    }

    // Adjacency matrix
    int A[MAX_NODES][MAX_NODES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // BFS
    int source;
    printf("Enter the starting node: ");
    scanf("%d", &source);
    if (source < 0 || source >= n) {
        printf("Invalid!\n");
        return;
    }
    printf("BFS -> ");
    BFS(A, n, V, source);
    printf("\n");
}


void enqueue(int value) {
	if (rear == n - 1)
		return;
    if (front == -1)
        front = 0;
	rear++;
	queue[rear] = value;
}

int dequeue() {
	if (front == -1)
		return -1;
	int value = queue[front];
    front++;
    return value;
}
