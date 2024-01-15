#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int color;
    struct node *parent;
    struct node *left, *right;
};
struct node *root = NULL;
const int red = 1, black = 0;


// Rotations
void left_rotate(struct node *x) {
    struct node *y = x->right;
    // Turn y's left sub-tree to x's right sub-tree
    x->right = y->left;
    // Mark x as the parent of y's RST
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    // If x was the root, set y as the root
    if (x->parent == NULL)
        root = y;
    // If x was a left child
    else if (x == x->parent->left)
        x->parent->left = y;
    // If x was a right child
    else 
        x->parent->right = y;
    // Make x the left child of y and mark y as the parent of x
    y->left = x;
    x->parent = y;
}
void right_rotate(struct node *y) {
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}


// Create a Node
struct node *createNode() {
    struct node *node;
    node = (struct node *) malloc(sizeof(struct node));
    printf("Data: ");
    scanf("%d", &node->data);
    node->left = node->right = node->parent = NULL;
    node->color = red;
    return node;
}
// Balance the Red Black Tree after Insertion
void insert_fixup(struct node *z) {
    // Only when the parent of the node inserted is red
    if (z->parent != NULL && z->parent->color == red) {
        // If the parent is a left child
        if (z->parent->parent != NULL && z->parent == z->parent->parent->left) {
            struct node *uncle = z->parent->parent->right;
            // If the uncle is red, recolor the parent and uncle
            if (uncle != NULL && uncle->color == red) {
                z->parent->color = uncle->color = black;
                // Recolor the grandparent 
                z->parent->parent->color = red;
                // Recheck the conditions for the grandparent
                z = z->parent->parent;
            }
            // If the uncle is black, rotate and recolor
            else {
                // If the node is the right child, do left rotation
                if (z->parent->right != NULL && z == z->parent->right) {
                    // Rotate the parent to the right to transform this case to the next case
                    z = z->parent;
                    left_rotate(z);
                }
                // Now the red node is the left child of red parent.
                // Do recoloring, followed by right rotation of the grandparent
                z->parent->color = black;
                z->parent->parent->color = red;
                right_rotate(z->parent->parent);
            }
        }
        // If the parent is a right child, do the cases above with "right" and "left" interchanged
        else {
            struct node *uncle = z->parent->parent->left;
            if (uncle != NULL && uncle->color == red) {
                z->parent->color = uncle->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else {
                if (z->parent != NULL && z == z->parent->left) {
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                left_rotate(z->parent->parent);
            }
        }
    }
    root->color = black;
}
// BST Insertion
void insert(struct node *z) {
    struct node *x = root, *y = NULL;
    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    // If the tree was empty
    if (y == NULL)
        root = z;
    // If the node is to be inserted as the left child
    else if (z->data < y->data) 
        y->left = z;
    else 
        y->right = z;    
    z->left = z->right = NULL;
    if (z == root) {
        z->color = black;
        return;
    }   
    z->color = red;
    insert_fixup(z);
}

// Balance the RB Tree after deletion
void delete_fixup(struct node *x) {
    // If the node is black
    while (x != root && x->color == black) {
        // If the node is a left child
        if (x == x->parent->left) {
            struct node *sibling = x->parent->right;
            // If the sibling is red
            if (sibling->color == red) {
                // Swap colors of parent and sibling
                x->parent->color = red;
                sibling->color = black;
                // Rotate parent towards DB
                left_rotate(x->parent);
                sibling = x->parent->right;
            }
            // If the sibling is black and both its children are black
            if (sibling->left->color == black && sibling->right->color == black) {
                // Make the sibling red
                sibling->color = red;
                // Add extra black to the parent (repeat)
                x = x->parent;
            }
            else {
                // If the sibling is black and its rear child is red
                if (sibling->right->color == black) {
                    // Swap the color of sibling and rear child
                    sibling->left->color = black;
                    // Rotate the sibling opposite to DB
                    right_rotate(sibling);
                    sibling = x->parent->right;
                }
                // If the sibling is black and the far child is red
                sibling->color = sibling->parent->color;
                // Swap the color of the parent and the far child
                sibling->right->color = black;
                x->parent->color = black;
                // Rotate parent towards DB
                left_rotate(x->parent);
                x = root;
            }
        // If the node is a right child
        } else {
            struct node *sibling = x->parent->left;
            if (sibling->color == red) {
                x->parent->color = red;
                sibling->color = black;
                right_rotate(x->parent);
                sibling = x->parent->left;
            }
            if (sibling->left->color == black && sibling->right->color == black) {
                sibling->color = red;
                x = x->parent;
            } else {
                if (sibling->left->color == black) {
                    sibling->right->color = black;
                    left_rotate(sibling);
                    sibling = x->parent->left;
                }
                sibling->color = sibling->parent->color;
                sibling->left->color = black;
                x->parent->color = black;
                right_rotate(x->parent);
                x = root;
            }            
        }
        x->color = black;
    }
    return;
}
// Return the minimum node in a Tree
struct node *find_min(struct node *root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}
// BST Deletion with Color Replacement
struct node *delete(struct node *root, int value) {
	if (root == NULL) {
		printf("Not found!\n");
		return root;
	}
	struct node *temp;
	if (value < root->data) {
		root->left = delete(root->left, value);
	} else if (value > root->data) {
		root->right = delete(root->right, value);
	} else {
		if (root->left == NULL) {
			temp = root->right;
			free(root);
            delete_fixup(temp);
			return temp;
		} else if (root->right == NULL) {
			temp = root->left;
			free(root);
            delete_fixup(temp);
			return temp;
		} else {
            struct node *successor = find_min(root->right);
            root->data = successor->data;
            root->color = successor->color;
            root->right = delete(root->right, root->data);
            temp = successor->right;
        }
        // delete_fixup(successor->right);
	}
    delete_fixup(temp);
	return root;
}
void deletion() {
	int value;
	printf("Node: ");
	scanf("%d", &value);
	root = delete(root, value);
}


// Display
void preOrder(struct node *root) {
    if (root == NULL) 
        return;
    if (root->color == red)
        printf("%dR ", root->data);
    else 
        printf("%dB ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node *root) {
    if (root == NULL) 
        return;
    inOrder(root->left);
    if (root->color == red)
        printf("%dR ", root->data);
    else 
        printf("%dB ", root->data);
    inOrder(root->right);
}
void postOrder(struct node *root) {
    if (root == NULL) 
        return;
    postOrder(root->left);
    postOrder(root->right);
    if (root->color == red)
        printf("%dR ", root->data);
    else 
        printf("%dB ", root->data);
}
void display() {
    printf("PreOrder: ");
    preOrder(root);
    printf("\nInOrder: ");
    inOrder(root);
    printf("\nPostOrder: ");
    postOrder(root);
    printf("\n");
}


void main() {
    while (1) {
        int choice;
        printf("Enter 1: Display, 2: Insert, 3: Delete --- ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insert(createNode());
            display();
            break;
        case 3:
            deletion();
            display();
            break;
        
        default:
            return;
        }
    }    
}