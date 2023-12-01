#include <stdio.h>
#include <stdlib.h>


int unique(int arr[], int size, int value);


void main() 
{
	int n;
	printf("Enter the size of the universal set: ");
	scanf("%d", &n);
	int U[n];

	// Read the elements in the universal set
	for (int i = 0; i < n; i++) {
		printf("Element %d: ", i + 1);
		scanf("%d", &U[i]);
		if (unique(U, i, U[i]) == 1) {
			i--;
			printf("Element already exists!\n");
			continue;
		}
		
	}


	// Read the two sets
	int n1, n2, S1[n], S2[n], element;
	printf("Enter the size of set 1: \n");
	scanf("%d", &n1);
	int set1[n1];
	printf("Enter the elements in set 1: \n");
	for (int i = 0; i < n1; i++) {
		printf("")
		scanf("%d", &element);
		if (unique(set1, i, element)) {
			set1[i] == element;
		} else {
			printf("Element must be unique!\n");
			i--;
		}
		
	}
	
	printf("Enter the size of set 2: \n");
	scanf("%d", &n2);
	printf("Enter the elements in set 1: ");
	for (int i = 0; i < n2; i++) {
		
	}	

	// Print the sets
	for (int i = 0; i < n; i++)
		printf("%d ", U[i]);
}


// Make sure a value is unique in an array
int unique(int arr[], int size, int value) {
	for (int j = 0; j < size; j++) {
		if (arr[j] == value) {
			return 1;
		}
	}
	return 0;
}















