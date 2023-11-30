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
void deletion();
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


void insertion() {
	struct node *newnode, *temp;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Element: ");
	scanf("%d", &newnode->data);

	// If empty
	if (head == NULL) {
		head = newnode;
		newnode->next = newnode;
		display(head);
		size++;
		return;
	}

	// Insertion at the beginning
	void beginning() {
		newnode->next = head;
		temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = newnode;
		head = newnode;
	}

	// Insertion at the end
	void end() {
		temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = newnode;
		newnode->next = head;
	}

	// Insertion at any position
	void anypos() {
		int position;
		printf("Enter the position to insert into: ");
		scanf("%d", &position);
		if (position <= 1 || position >= size) {
			printf("Invalid position!\n");
			return;
		}
		int i = 2;
		temp = head;
		while (i < position) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}		

	int type;
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
	scanf("%d", &type);
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
}


void deletion() {
	struct node *temp, *delnode;
	temp = head;

	if (head == NULL)
		return;

	// If only one node left in the list
	if (head->next == head) {
		head = NULL;
		free(temp);
		display(head);
		return;
	}

	// Deletion from the beginning
	void beginning() {
		delnode = head;
		while (temp->next != head)
			temp = temp->next;
		head = head->next;
		temp->next = head;
		free(delnode);
		size--;
	}

	// Deletion from the end
	void end() {
		while (temp->next->next != head)
			temp = temp->next;
		delnode = temp->next;
		temp->next = head;
		free(delnode);
		size--;
	}

	// Deletion from a particular position
	void anypos() {
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position >= size || position <= 1) {
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
		size--;
	}

	int type;
	printf("Enter 0 to delete from the beginning, 1 to delete from the end, 2 to delete from any positon: ");
	scanf("%d", &type);
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
}


void display(struct node *ptr) {

	// If empty
	if (head == NULL) {
		printf("NULL\n");
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







