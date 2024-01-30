#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Value: ");
    scanf("%d", &newnode->data);

    if  (front == NULL) {
        front = rear = newnode;
        newnode->next = NULL;
        return;
    }
    rear->next = newnode;
    rear = newnode;
    newnode->next = NULL;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    } else if (front == rear) {
        rear = NULL;
    }
    struct node* temp = front;
    front = front->next;
    free(temp);
}

void display(struct node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    display(node->next);
}

void main() {
    while (1) {
        int choice;
        printf("Enter 0 to display, 1 to enqueue, 2 to dequeue, 5 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            display(front);
            printf("\n");
            break;
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 5:
            return;
        default:
            break;
        }
    }    
}
