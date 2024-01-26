#include <stdio.h>

#define size 100

int array[size];
int n;

void display();
void createArray();
void insertion();
void deletion();
int search();
int bubbleSort();
void reverseArray();


void main() {
    createArray();    
    while (1) {
        int choice;
        printf("Enter 1 to Create, 2 to Insert, 3 to Delete, 4 to Display, 5 to Search, 6 to Sort, 7 to Reverse, 8 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            createArray();
            break;
        case 2:
            insertion();
            break;
        case 3:
            deletion();
            break;
        case 4:
            display();
            break;
        case 5:
            search();
            break;
        case 6:
            bubbleSort();
            break;
        case 7:
            reverseArray(0, n - 1);
            break;
        case 8:
            return;
        default:
            break;
        }
    }
    
}


// DISPLAY
void display() {
    if (n == 0) {
        printf("Array is Empty!\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}


// CREATION
void createArray() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
}


// INSERTION
void insertionAtBeginning(int element) {
    // Shift all elements to the right
    for (int i = n; i > 0; i--)
        array[i] = array[i - 1];
    array[0] = element;
    n++;
}
void insertionAtEnd(int element) {
    array[n] = element;
    n++;
}
void insertionAtAnyPos(int element) {
    int pos;
    printf("Position: ");
    scanf("%d", &pos);
    if (pos > n) {
        printf("Invalid Position!\n");
        return;
    }
    n++;
    // Shift all elements from the position to insert to the end, to right
    for (int i = n; i > pos; i--)
        array[i] = array[i - 1];
    array[pos] = element;
}
void insertion() {
    int choice, element;
    printf("Element: ");
    scanf("%d", &element);
    printf("Enter 1 for Beginning, 2 for End, 3 for Any Position: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        insertionAtBeginning(element);
        break;
    case 2:
        insertionAtEnd(element);
        break;
    case 3:
        insertionAtAnyPos(element);
        break;
    default:
        break;
    }
    display();
}


// DELETION
void deletionAtBeginning() {
    // Shift all elements to left
    for (int i = 0; i < n; i++)
        array[i] = array[i + 1];
    n--;
}
void deletionAtEnd() {
    n--;
}
void deletionAtAnyPos() {
    int pos;
    printf("Position: ");
    scanf("%d", &pos);
    if (pos > n - 1) {
        printf("Invalid Position!\n");
        return;
    }
    // Shift all elements from the position to insert to the end, to left
    for (int i = pos; i < n; i++)
        array[i] = array[i + 1];
    n--;
}
void deletion() {
    if (n == 0) {
        printf("Array is Empty!\n");
        return;
    }
    int choice;
    printf("Enter 1 for Beginning, 2 for End, 3 for Any Position: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        deletionAtBeginning();
        break;
    case 2:
        deletionAtEnd();
        break;
    case 3:
        deletionAtAnyPos();
        break;
    default:
        break;
    }
    display();
}


// Linear Search
int search() {
    int x;
    printf("Element To Search: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            printf("Element %d Found at Position: %d!\n", x, i);
            return i;
        }
    }
    printf("Element Not Found!\n");
    return -1;
}


// Bubble Sort
int bubbleSort() {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }        
        }    
    }
    printf("Sorted Successfully!\n");
    display();
}


// Array Reversal using recursion
void reverseArray(int first, int last) {
    // If we reached the middle of the array
    if (first >= last) {
        printf("Reversed Successfully!\n");
        display();
        return;
    }
    // Swap elements at the ends
    int temp = array[first];
    array[first] = array[last];
    array[last] = temp;
    // Call the function on array[first + 1:last - 1]
    reverseArray(first + 1, last - 1);
}
