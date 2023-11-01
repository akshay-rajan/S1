#include <stdio.h>
#include <stdlib.h>


// Define node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *head = NULL;
int isEmpty = 1;


int insert();
int preOrder(struct node *);


void main()
{
    while (1) {
        int choice;
        printf("Enter 0 to display, 1 to insert, 5 to exit:");
        scanf("%d", &choice);
        switch(choice) {
            case 0:
                preOrder(head);
                printf("\n");
                break;
            case 1:
                insert();
                break;
            case 5:
                return;
            default:
                break;
        }
    }
}


// Insert an element into the tree
int insert()
{
    int value, left;
    struct node *newnode, *temp;
    printf("Element: ");
    scanf("%d", &value);

    // Creation of new node
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    // Insert as root of the tree, if no element is present
    if (isEmpty) {
        head = newnode;
        isEmpty = 0;
        return 0;
    }

    // Reach the appropriate position to insert
    temp = head;
    while (temp != NULL) {
        if (temp->data < value) {
            if (temp->left == NULL) {
                temp->left = newnode;
                return 0;
            }
            temp = temp->left;
        }
        else {
            if (temp->right == NULL) {
                temp->right = newnode;
                return 0;
            }
            temp = temp->right;
        }
    }
    return 0;
}


// Traverse through the elements in the order: Root->Left->Right
int preOrder(struct node *root)
{
    if (root == NULL)
        return 1;
    printf("%d -> ", root->data);
    
    // Recursively traverse through the left and right sub trees
    preOrder(root->left);
    preOrder(root->right);
}

