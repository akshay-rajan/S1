#include <stdio.h>
#include <stdlib.h>

#define size 10

int stack[size];
int top = -1;


int push();
int pop();
void display();
int peek();
int count();
int IsEmpty();
int IsFull();


void main()
{
	while (1) {
		int choice;
		printf("Enter 0 to display the stack, 1 to push, 2 to pop, 3 to peek, 4 to display the count, or 5 to exit: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 0:
				display();
				break;
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				printf("%d\n", peek());
				break;
			case 4:
				printf("%d\n", count());
				break;
			case 5:
				exit(0);
			default:
				break;
		}
	}	
}


// Print the stack
void display()
{
	if (IsEmpty())
		return;
	
	for (int i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}


// Add an element
int push()
{
	// Check if stack is full
	if (IsFull())
	{
		printf("Overflow!\n");
		return 0;
	}
	
	// Add an element to the top of the stack
	int element;
	printf("Element: ");
	scanf("%d", &element);
	top++;
	stack[top] = element;
    display();
    return element;
}


// Remove an element
int pop()
{
	// Check if stack is empty
	if (IsEmpty())
	{
		printf("Underflow!\n");
		return 0;
	}
	
	// Remove the element at the top of the stack and return it
	int element = stack[top];
	top--;
    display();
	return element;
}


// Return an element at a particular position
int peek()
{
	int pos;
	printf("Position: ");
	scanf("%d", &pos);
	
	// Validation
	if (pos > top + 1 || pos < 0)
	{
		printf("Invalid!\n");
		return 1;
	}
	
	int element = stack[pos - 1];
	return element;
}


// Return total number of elements in the stack
int count()
{
	return top + 1;
}


int IsEmpty()
{
	if (top == -1)
		return 1;
	return 0;	
}

int IsFull()
{
	if (top == size - 1)
		return 1;
	return 0;
}



