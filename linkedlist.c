#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};


int size = 0;
struct node *head = NULL;
struct node *newnode;


void display();
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
				display();
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
	// Read position and element
	int position;
	newnode = (struct node *) malloc (sizeof(struct node));
	printf("Position: ");
	scanf("%d", &position);	
	if (position > size) {
		free(newnode);
		printf("Invalid!\n");
		return 1;
	}
	printf("Element: ");
	scanf("%d", &newnode->data);

	struct node *temp = head;
	int i = 1;

	// Insertion at the beginning
	if (position == 0) {
		newnode->next = head;
		head = newnode;
	} else {
		// Insertion at the position
		while (i < position) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	size++;
	return 0;
}


// Deletion from any position
int deletion()
{
	int position;
	newnode = (struct node *) malloc (sizeof(struct node));
	printf("Position: ");
	scanf("%d", &position);	
	if (position > size) {
		printf("Invalid!\n");
		return 1;
	}

	struct node *temp, *delnode;
	temp = head;
	int i = 0;
	while (i < position - 1) {
		temp = temp->next;
		i++;
	}	

	delnode = temp->next;
	temp->next = delnode->next;
	free(delnode);
	return 0;
}


// Display the linked list
void display()
{
	struct node *temp = head;
	while (temp != NULL) {
		if (temp->next == NULL) {
			printf("%d\n", temp->data);
			return;
		}
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
}


