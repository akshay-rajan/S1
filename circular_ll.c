#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};


int size = 0, flag = 0;
struct node *head = NULL;
void display(struct node *ptr);


void insertion();
void display(struct node *ptr);


void main() {
	int choice;
	while (1) {
		printf("Enter 0 to display, 1 to insert, 2 to delete or 5 to exit: ");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				display(head);
				break;
			case 1:
				insertion();
				break;
			case 5:
				return;
			default:
				break;
		}
	}
}


void insertion() {
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Element: ");
	scanf("%d", &newnode->data);

	// If empty
	if (head == NULL) {
		head = newnode;
		newnode->next = head;
	}
	// Insertion at the beginning
	else {
		newnode->next = head;
		head = newnode;
	}
	
	display(head);
	size++;
}


void display(struct node *ptr) {

	// If empty
	if (head == NULL) {
		printf("The linked list is empty!\n");
		return;
	}
	
	// If the whole list has been traversed
	if (ptr->next == head) {
		printf("%d\n", ptr->data);
		return;		
	}
	
	printf("%d -> ", ptr->data);
	
	display(ptr->next);
}







