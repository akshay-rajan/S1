#include <stdio.h>

#define size 10

int stack[size];
int top = -1;


int isEmpty() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return 1;
    }
    return 0;
}

int isFull() {
    if (top == size - 1) {
        printf("Stack Overflow!\n");
        return 1;
    }
    return 0;
}

void display() {
    if (isEmpty())
        return;
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int count() {
    return top + 1;
}

// Insert an element into the stack
void push() {
    if (isFull())
        return;
    top++;
    int value;
    printf("Value: ");
    scanf("%d", &value);
    stack[top] = value;
}

// Remove an element from the stack
int pop() {
    if (isEmpty())
        return -1;
    int value = stack[top];
    top--;
    return value;
}

// Return an element at a particular position
int peek() {
    if (isEmpty())
        return -1;
    int pos;
    printf("Position: ");
    scanf("%d", &pos);
    if (pos  < 1 || pos > top) {
        printf("Invalid Position!");
        return -1;
    }
    return stack[pos - 1];
}


void main() {
	while (1) {
		int choice;
		printf("Enter 0 to display the stack, 1 to push, 2 to pop, 3 to peek, 4 to display the count, 5 to exit: ");
		scanf("%d", &choice);
		switch (choice) {
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
				return;
			default:
				break;
		}
	}	
}
