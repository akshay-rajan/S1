#include <stdio.h>
#include <stdlib.h>

#define size 5


void display();
int enqueue();
int dequeue();
int IsEmpty();
int IsFull();


int queue[size];
int front = -1;
int rear = -1;


void main()
{
	while (1)
	{
		int choice;
		printf("Enter 0 to display, 1 to enqueue, 2 to dequeue, 5 to exit: ");
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


void display()
{
    if (IsEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

	for (int i = front; i != rear; i = (i + 1) % size)
	{
		printf("%d ", queue[i]);
	}
	printf("%d\n", queue[rear]);
}


int enqueue()
{
	if (IsFull())
	{
		printf("Overflow!\n");
		return 1;
	}

	int value;
	printf("Element: ");
	scanf("%d", &value);
	
	// If empty
	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	// If rear is at the initial point and front not there
	else if (rear == size - 1 && front != 0)
	{
		rear = 0;
	}
	// If rear has not completed a cycle
	else
	{
		rear = (rear + 1) % size;
	}
	
	
	queue[rear] = value;
    display();
	return value;
}


int dequeue()
{
	if (IsEmpty())
	{
		printf("Underflow!\n");
		return 1;
	}
	int value = queue[front];
	
	// If no element remains, but front and end are not at the starting position
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	// If front is at the end of the queue
	else if (front == size - 1)
	{
		front = 0;
	}
	// Otherwise, increment front
	else
	{
		front++;
	}
    display();
	return value;
}


int IsFull()
{
	if ((rear + 1) % size == front)
		return 1;
	return 0;
}

int IsEmpty()
{
	if (front == -1 && rear == -1)
		return 1;
	return 0;
}
