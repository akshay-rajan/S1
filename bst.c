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
int delete();
int display();


void main()
{
    while (1) {
        int choice;
        printf("Enter 0 to display, 1 to insert, 2 to delete, 5 to exit:");
        scanf("%d", &choice);
        switch(choice) {
            case 0:
				display();
                break;
            case 1:
                insert();
                break;
			case 2:
				delete();
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
    int value;
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
        if (temp->data > value) {
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


// Delete an element of a particular value
int delete()
{
	// Read the value to delete
	int value, left;
	printf("Enter the value to delete: ");
	scanf("%d", &value);

	// Find the node with the value
	struct node *temp, *parent;
	temp = head;
    while (temp != NULL) {
        // If the value is lesser, search left half
        if (temp->data > value) {
			left = 1;
			parent = temp;
            temp = temp->left;
        } 
        // If the value is greater, search right half
        else if (temp->data < value) {
			left = 0;
			parent = temp;
            temp = temp->right;
        }
        // If the node to delete has been found
		else {
			if (left == 1) {
                // If the node is the left child of its parent
				if (temp->left != NULL) {
                    // If the node has a left child, replace the node with it
					parent->left = temp->left;				
				}
				else if (temp->right != NULL) {
                    // If the node has no left child, but a right child is present
					parent->left = temp->left;				
				}
				else {
                    // If the node is a leaf node
					parent->left = NULL;
				}
			} 
            else {
                // If the node is the right child of its parent, same method used above
				if (temp->left != NULL) 
					parent->right = temp->left;	
				else if (temp->right != NULL)
					parent->right = temp->left;				
				else
					parent->right = NULL;
			}
			free(temp);
			return 0;
		}
    }
    // If no such value is present in the tree
    printf("Cannot find the node!\n");
    return 1;
}


// Perform all three traversals
int display(){
    if (head == NULL) {
        printf("Tree is empty!\n");
        return 1;
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

    // Traverse through the elements in the order: Left->Root->Right
    int inOrder(struct node *root)
    {
        if (root == NULL)
            return 1;

        inOrder(root->left);

        printf("%d -> ", root->data);
        
        inOrder(root->right);
    }

    // Traverse through the elements in the order: Left->Right->Root
    int postOrder(struct node *root)
    {
        if (root == NULL)
            return 1;

        postOrder(root->left);
        postOrder(root->right);

        printf("%d -> ", root->data);   
    }

    // Function calls
    printf("Preorder: ");
    preOrder(head);
    printf("\nInorder: ");
    inOrder(head);
    printf("\nPostorder: ");
    postOrder(head);
    printf("\n");
    return 0;
}

