#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
	struct node *prev;
};


int size = 0;
struct node *head = NULL;
struct node *tail = NULL;


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
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
	scanf("%d", &type);
	printf("Element: ");
	scanf("%d", &newnode->data);
	
	// If empty
	if (head == NULL) {
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
		tail = newnode;
		size++;
		display(head);
		return 0;
	}

	// Insertion at the beginning	
	void beginning() {
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		newnode->prev = NULL;
	}


	// Insertion at the end
	void end() {
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
		newnode->next = NULL;
	}

	// Insertion at any position
	void anypos() {
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position <= 1 || position >= size) {
			printf("Invalid!\n");
			return;
		}
		struct node *temp, *temp1;
		temp = head;
		int i = 1;
		while (i < position) {
			if (temp->next != NULL) {
				temp1 = temp;
				temp = temp->next;
			}
			i++;
		}
		newnode->next = temp;
		temp->prev = newnode;
		temp1->next = newnode;
		newnode->prev = temp1;
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
		default:
			return 0;
	}
	size++;
	display(head);
	return 0;
}


int deletion()
{
	if (head == NULL)
		return 1;

	int type;
	struct node *delnode;
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
	scanf("%d", &type);
	
	// Deletion at the beginning
	void beginning() {
		delnode = head;
		head->next = delnode->next;
		delnode->next = head;
	}



	free(delnode);
	
	switch (type) {
		case 0:
			beginning();
			break;
/*		case 1:
			end();
			break;
		case 2:
			anypos();
			break;*/
	}
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















