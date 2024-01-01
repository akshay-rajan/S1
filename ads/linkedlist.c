#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

int size = 0;
struct node *head = NULL;
struct node *newnode, *temp, *temp1, *delnode;


void display(struct node *ptr);
int insertion();
int deletion();
void reverse();


void main() {
	int choice;
	while (1) {
		printf("Enter 0-> display, 1-> insert, 2-> delete, 3->reverse, 5-> exit: ");
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
			case 3:
				reverse();
				break;
			case 5:
				return;
			default:
				break;
		}
	}
}

// Insertion
void ins_beginning() {
	newnode->next = head;
	head = newnode;
}
void ins_end() {
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = NULL;
}
void ins_anypos() {
	int position;
	printf("Position: ");
	scanf("%d", &position);
	if (position < 1 || position > size + 1) {
		printf("Invalid!\n");
		return;
	}
	if (position == 1) {
		ins_beginning();
		return;
	} else if (position == size + 1) {
		ins_end();
		return;
	}
	int i = 2;
	while (i < position) {
		if (temp->next != NULL) 
			temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}
int insertion() {
	newnode = (struct node *) malloc(sizeof(struct node));
	temp = head;
	printf("Element: ");
	scanf("%d", &newnode->data);

	if (size == 0) {
		ins_beginning();
		size++;
		display(head);
		return 0;
	}
	int type;
	printf("Enter 0-> insertion at the beginning, 1-> insertion at the end, 2-> insertion at any position: ");
	scanf("%d", &type);
	switch (type) {
		case 0:
			ins_beginning();
			break;
		case 1:
			ins_end();
			break;
		case 2:
			ins_anypos();
			break;
	}
	size++;
	display(head);
	return 0;
}

// Deletion
void del_beginning() {
	head = temp->next;
	free(temp);
}
void del_end() {
	while (temp->next != NULL) {
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = NULL;
	free(temp);
}
void del_anypos() {
	int position;
	printf("Position: ");
	scanf("%d", &position);
	if (position > size) {
		printf("Invalid!\n");
		return;
	}
	if (position == 1) {
		del_beginning();
		return;
	} else if (position == size) {
		del_end();
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
int deletion() {
	temp = head;
	if (size <= 1) {
		if (size == 1) {
			del_beginning();
			size--;
		} else { 
			printf("The list is empty!\n");
		}
		display(head);
		return 0;
	}
	int type;
	printf("Enter 0-> delete from the beginning, 1-> delete from the end, 2-> delete from any positon: ");
	scanf("%d", &type);
	switch (type) {
		case 0:
			del_beginning();
			break;
		case 1:
			del_end();
			break;
		case 2:
			del_anypos();
			break;
	}
	size--;
	display(head);
	return 0;
}


// Reverse the order of nodes in the linked list
void reverse() {
	struct node *previous, *current, *next;
	previous = next = NULL;
	current = head;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
	display(head);
}


// Display the linked list
void display(struct node *ptr)
{
	if (ptr == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", ptr->data);

	display(ptr->next);
}

