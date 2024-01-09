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
        printf("Enter 1: Display, 2: Insert --- ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insert(createNode());
            display();
            break;
        
        default:
            return;
        }
    }    
    return;
}