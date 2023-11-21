#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};


int size = 0;
struct node *head = NULL;


void display(struct node *ptr);
int insertion();
int deletion();


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
			case 2:
				deletion();
				break;
			case 5:
				return;
			default:
				break;
		}
	}
}


// Insertion at any position
int insertion()
{
	int type;
	struct node *newnode, *temp, *temp1;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
	scanf("%d", &type);
	temp = head;
	printf("Element: ");
	scanf("%d", &newnode->data);

	void beginning() {
		newnode->next = head;
		head = newnode;
	}
	void end() {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
	void anypos() {
		// Read position and element
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position <= 1 || position > size - 1) {
			printf("Invalid!\n");
			return;
		}

		int i = 2;
		// Insertion at the position
		while (i <= position) {
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
		size++;
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


// Deletion from any position
int deletion()
{
	int type;
	struct node *temp, *temp1, *delnode;
	temp = head;
	printf("Enter 0 to delete from the beginning, 1 to delete from the end, 2 to delete from any positon: ");
	scanf("%d", &type);

	void beginning() {
		head = temp->next;
		free(temp);
	}
	void end() {
		while (temp->next != NULL) {
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = NULL;
		free(temp);
	}
	void anypos() {
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position > size) {
			printf("Invalid!\n");
			return;
		}

		int i = 2;
		while (i < position) {
			temp = temp->next;
			i++;
		}	

		delnode = temp->next;
		temp->next = delnode->next;
		free(delnode);
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
	display(head);
	return 0;
}


// Display the linked list
void display(struct node *ptr)
{
	if (ptr == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", ptr->data);

	// Recursion
	display(ptr->next);
}

