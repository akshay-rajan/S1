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
void display();


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
	if (head == NULL) {
		return 1;
	}

	int type;
	struct node *delnode, *temp;
	printf("Enter 0 for deletion at the beginning, 1 for deletion at the end or 2 for deletion at any position: ");
	scanf("%d", &type);
	
	// If only one node remaining
	if (size == 1) {
		delnode = head;
		head = NULL;
		tail = NULL;
		free(delnode);
		size--;
		display(head);
		return 0;
	}
	
	// Deletion at the beginning
	void beginning() {
		delnode = head;
		temp = head->next;
		head = temp;
		temp->prev = NULL;
	}
	
	// Deletion at the end
	void end() {
		delnode = tail;
		temp = tail->prev;
		tail = temp;
		temp->next = NULL;
	}

	// Deletion at any position
	void anypos() {
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position <= 1 || position >= size || size < 3) {
			printf("Invalid!\n");
			return;
		}
		struct node *temp, *temp1, *temp2;
		temp = head;
		int i = 1;
		while (i < position) {
			if (temp->next != NULL) {
				temp1 = temp;
				temp = temp->next;
				temp2 = temp->next;
			}
			i++;
		}
		delnode = temp;
		temp1->next = temp2;
		temp2->prev = temp1;
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
	free(delnode);
	size--;
	display(head);
	return 0;
}


// Display the doubly linked list
void display()
{
	if (size == 0) {
		printf("The linked list is empty!\n");
		return;
	}
	
	// From head to tail
	void headtotail(struct node * ptr) {
		if (ptr == head)
			printf("Head ->");
		if (ptr == NULL) {
			printf("<- Tail\n");
			return;
		}
		printf("<- %d -> ", ptr->data);

		headtotail(ptr->next);		
	}

	// From tail to head
	void tailtohead(struct node *ptr) {
		if (ptr == tail)
			printf("Tail ->");
		if (ptr == NULL) {
			printf("<- Head\n");
			return;
		}
		printf("<- %d -> ", ptr->data);

		tailtohead(ptr->prev);
	}
	
	headtotail(head);
	tailtohead(tail);
}


