#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *root = NULL;
int isEmpty = 1;


int insert();
int display();
void deletion();


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
                display();
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

    // Insert as root of the tree, if tree is empty
    if (isEmpty) {
        root = newnode;
        isEmpty = 0;
        return 0;
    }

    // Reach the appropriate position to insert
    temp = root;
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


// Return the smallest node in a tree
struct node *find_min(struct node *root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

// Delete a node from a tree and return the root
struct node *delete(struct node *root, int value) {
	if (root == NULL) {
		printf("Not found!\n");
		return root;
	}
	
	// Find the node, while keeping track of the path taken to reach it
	struct node *temp;
	if (value < root->data) {
		root->left = delete(root->left, value);
	} else if (value > root->data) {
		root->right = delete(root->right, value);
	} else {
	// Reached the node to delete	
		// If only one child
		if (root->left == NULL) {
			temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			// (This is where the deletion of the inorder successor happens)
			temp = root->left;
			free(root);
			return temp;
		}	
		// IF THE NODE HAS TWO CHILDREN
		// Replace the data in the node with the data of its inorder successor
		root->data = find_min(root->right)->data;
		// Delete the inorder successor ,also maintaining the structure of the tree
		root->right = delete(root->right, root->data);
	}
	return root;
}

// Driver function that performs deletion
void deletion() {
	int value;
	printf("Enter the node to delete: ");
	scanf("%d", &value);
	root = delete(root, value);
	// If the tree is now empty
	if (root == NULL)
		isEmpty = 1;
	display();
}


// Perform all three traversals to display the tree
int display(){
    if (root == NULL) {
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
    preOrder(root);
    printf("NULL\nInorder: ");
    inOrder(root);
    printf("NULL\nPostorder: ");
    postOrder(root);
    printf("NULL\n");
    return 0;
}







