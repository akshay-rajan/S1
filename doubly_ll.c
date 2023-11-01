#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
	struct node *prev,
}


int size = 0;
struct node *head = NULL;
struct node *newnode;


void main()
{
	while (1) {
		int choice;
		printf("Enter 1 to insert, 2 to delete, 5 to exit: ");
		scanf("%d", &choice);
		switch (choice) {
			case 5:
				return;
		}
	}
}


// Insertion at the begining
int insertion()
{
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Element: ");
	scanf("%d", &newnode->data);
	
	// Insertion
	newnode->next = head;
	newnode->prev = NULL;
	head = newnode;
	head->prev = newnode;
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





