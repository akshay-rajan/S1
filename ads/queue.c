#include <stdio.h>
#include <stdlib.h>

#define size 5


void display();
int enqueue();
int dequeue();
int IsFull();
int IsEmpty();


int queue[size];
int front = -1, rear = -1;


void main() {
	while (1) {
		int choice;
		printf("Enter 0 to print, 1 to enqueue, 2 to dequeue, 5 to exit: ");
		scanf("%d", &choice);
		switch(choice) {
			case 0:
				display();
				break;
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 5:
				exit(0);
			default:
				break;
		}
	}
}


// Print the queue
void display()
{
	if (IsEmpty()) {
        printf("Queue is empty!\n");
		return;
    }
	for (int i = front; i <= rear; i++)
		printf("%d ", queue[i]);
	printf("\n");
}


// Add an element to the queue
int enqueue() {
	if (IsFull()){
		printf("Overflow!\n");
		return 1;
	}
	
    if (front == -1)
        front = 0;

	int item;
	printf("Element: ");
	scanf("%d", &item);
	queue[++rear] = item;
    display();
	return item;
}


// Remove an element from the queue
int dequeue() {
	if (IsEmpty()) {
		printf("Underflow!\n");
		return 1;
	}
	int element = queue[front++];
	if (front > rear)
		front = -1, rear = -1;	
    display();
	return element;
}


int IsFull() {
	if (rear == size - 1)
		return 1;
	return 0;
}

int IsEmpty() {
	if (front == -1 || front > rear)
		return 1;
	return 0;
}


