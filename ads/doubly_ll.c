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
struct node *newnode, *delnode, *temp;


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


// Insertion
void ins_beginning() {
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
	newnode->prev = NULL;
}
void ins_end() {
	newnode->prev = tail;
	tail->next = newnode;
	tail = newnode;
	newnode->next = NULL;
}
void ins_anypos() {
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
int insertion()
{
	newnode = (struct node *) malloc(sizeof(struct node));
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

	int type;
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
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
		default:
			return 0;
	}
	size++;
	display(head);
	return 0;
}


// Deletion
void del_beginning() {
	delnode = head;
	temp = head->next;
	head = temp;
	temp->prev = NULL;
}
void del_end() {
	delnode = tail;
	temp = tail->prev;
	tail = temp;
	temp->next = NULL;
}
void del_anypos() {
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
int deletion()
{
	if (head == NULL) {
		printf("The linked list is empty!\n");
		return 1;
	}
	
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
	
	int type;
	printf("Enter 0 for deletion at the beginning, 1 for deletion at the end or 2 for deletion at any position: ");
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
	free(delnode);
	size--;
	display(head);
	return 0;
}


// Display
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
void display()
{
	if (size == 0) {
		printf("The linked list is empty!\n");
		return;
	}	
	headtotail(head);
	tailtohead(tail);
}


