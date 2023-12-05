#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
int queue[100];
int front = -1, rear = -1;


void enqueue(int value);
int dequeue();


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
    int A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // BFS

    // Enqueue the source (here, 0) and mark it as visited
    enqueue(0);
    V[0] = 1;

    // Repeat until the queue is empty
    while (front <= rear) {
        // Perform dequeue and print the removed node
        int node = dequeue();
        printf("%d ", node);
        // For all adjacent nodes of the deleted node that are unvisited
        for (int i = 0; i < n; i++) {
            if (A[node][i] != 0 && !V[i]) {
                // Enqueue it and mark it as visited
                enqueue(i);
                V[i] = 1;
            }
        }
    }
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