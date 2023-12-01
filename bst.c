#include <stdio.h>
#include <stdlib.h>


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
int largest(struct node *root);
int deletion(struct node *root, int value);

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


// Insert a node into the tree
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


// Delete a node with a particular value
int delete()
{
	int value, left;
	printf("Enter the node to delete: ");
	scanf("%d", &value);

	// Find the node to delete: BST Search
	struct node *temp, *parent;
	temp = head;
	while (temp != NULL) {
	        if (temp->data > value) {
			if (temp->left != NULL) {
				left = 1;	
				parent = temp;
		        	temp = temp->left;
		       	}
        	} else if (temp->data < value) {
        		if (temp->right != NULL) {
        			left = 0;
				parent = temp;
				temp = temp->right;
        		}
		} else {
			// If the node has no children, simply delete
			if (temp->left == NULL && temp->right == NULL) {
				if (left)
					parent->left = NULL;
				else
					parent->right = NULL;
				free(temp);
			}
			// If the node has one child, replace the node with its child
			else if (temp->left == NULL || temp->right == NULL) {
				if (temp->left != NULL) {
					if (left)
						parent->left = temp->left;
					else
						parent->right = temp->left;
				} else {
					if (left)
						parent->left = temp->right;
					else
						parent->right = temp->right;
				}
				free(temp);
			}
			// If the node has two children, replace the node with its inorder predecesor
			else {
				struct node *predecessor;
				predecessor = temp->left;
				while (1) {
					if (predecessor->right != NULL)
						predecessor = predecessor->right;
				}
				if (left)
					return 1;
				else 
					return 1;	
			}
			return 0;
		}
	}
	// If no such value is present in the tree
	printf("Cannot find the node!\n");
	return 1;
}


int deletion(struct node *root, int value) {
	if (root == NULL) {
		printf("Not found!\n");
		return 1;
	}
	
	if (value < root->data) {
		deletion(root->left, value);
	} else if (value > root->data) {
		deletion(root->right, value);
	}
	// https://www.javatpoint.com/deletion-in-binary-search-tree
}


// Get the largest node in a tree
int largest(struct node *root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
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







