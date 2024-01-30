#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
struct node *top = NULL;

void push() {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("Value: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;    
}

void pop() {
    if  (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
}

void display(struct node *top) {
    if (top == NULL) {
        return;
    }
    printf("%d ", top->data);
    display(top->next);
}

void main() {
    while (1) {
        int choice;
        printf("Enter 0 to display, 1 to push, 2 to pop, 5 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
                case 0:
                    display(top);
                    printf("\n");
                    break;
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 5:
                    return;
                default:
                    break;
        }
    }
}
