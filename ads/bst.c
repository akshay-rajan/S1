#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;


int display();
void insertion();
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


// Insert a node into the tree and return the root
struct node *insert(struct node *root, struct node *newnode) {
    if (root == NULL) {
        root = newnode;
    } else if (root->data > newnode->data) {
        root->left = insert(root->left, newnode);
    } else {
        root->right = insert(root->right, newnode);
    }
    return root;
}
void insertion()
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Element: ");
    scanf("%d", &newnode->data);
    newnode->left = newnode->right = NULL;
    root = insert(root, newnode);
    display();
    return;
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
	display();
}


// Perform all three traversals to display the tree
// Root->Left->Right
void preOrder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d -> ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
// Left->Root->Right
void inOrder(struct node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d -> ", root->data);
    inOrder(root->right);
}
// Left->Right->Root
void postOrder(struct node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d -> ", root->data);   
}
int display(){
    if (root == NULL) {
        printf("Tree is empty!\n");
        return 1;
    }

    printf("Preorder: ");
    preOrder(root);
    printf("NULL\nInorder: ");
    inOrder(root);
    printf("NULL\nPostorder: ");
    postOrder(root);
    printf("NULL\n");
    return 0;
}







