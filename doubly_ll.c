#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
	struct node *prev;
};


int size = 0;
struct node *head = NULL;


int insertion();
int deletion();
void display(struct node *ptr);


void main()
{
	while (1) {
		int choice;
		printf("Enter 0 to display, 1 to insert, 2 to delete, 5 to exit: ");
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
		}
	}
}


int insertion()
{
	int type;
	struct node *newnode, *temp;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
	scanf("%d", &type);
	printf("Element: ");
	scanf("%d", &newnode->data);

	// Insertion at the beginning	
	void beginning() {
		if (head == NULL) {
			newnode->next = NULL;
			head = newnode;		
			newnode->prev = head;
			return;
		}
	
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		newnode->prev = head;
		return;
	}


	// Insertion at the end
	void end() {
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = NULL;
	}

	// Insertion at any position
	void anypos() {
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position < 1 || position > size) {
			printf("Invalid!\n");
			return;
		}
		int i = 2;
		while (i < position) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;

	}

	switch (type) {
		case 0:
			beginning();
			break;
		case 1:
			end();
			break;
		case 2:
			anypos();
			break;
	}
	size++;
	display(head);
	return 0;
}


// Deletion at the beginning
int deletion()
{
	if (head == NULL)
		return 1;

	struct node *delnode;
	delnode = head->next;
	head->next = delnode->next;
	delnode->next->prev = head;
	free(delnode);
}


// Display the doubly linked list
void display(struct node *ptr)
{
	if (ptr == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d <-> ", ptr->data);

	// Recursion
	display(ptr->next);
}















