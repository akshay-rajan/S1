#include <stdio.h>


int isPresent(int arr[], int size, int value);


void main() 
{
	int n, n1, n2, element;

	// Read the elements in the universal set
	printf("Enter the size of the universal set: ");
	scanf("%d", &n);
	int U[n];
	for (int i = 0; i < n; i++) {
		printf("Element %d: ", i + 1);
		scanf("%d", &U[i]);
		if (isPresent(U, i, U[i])) {
			printf("Element already exists!\n");
			i--;
			continue;
		}
	}

	// Read the elements in the two sets
	printf("Enter the size of set 1: ");
	scanf("%d", &n1);
	if (n1 > n || n1 < 0) {
		printf("Invalid size!\n");
		return;
	}
	int set1[n1];
	printf("Enter the elements in set 1: \n");
	for (int i = 0; i < n1; i++) {
		printf("set1[%d]: ", i);
		scanf("%d", &element);
		// If the element is unique in the current set, and present in the universal set
		if (!isPresent(set1, i, element) && isPresent(U, n, element))
			set1[i] = element;
		else {
			printf("Element must be unique and present in the universal set!\n");
			i--;
		}	
	}
	printf("Enter the size of set 2: ");
	scanf("%d", &n2);
	if (n2 > n || n2 < 0) {
		printf("Invalid size!\n");
		return;
	}
	int set2[n2];
	printf("Enter the elements in set 2: \n");
	for (int i = 0; i < n2; i++) {
		printf("set2[%d]: ", i);
		scanf("%d", &element);
		if (!isPresent(set2, i, element) && isPresent(U, n, element))
			set2[i] = element;
		else {
			printf("Element must be unique and present in the universal set!\n");
			i--;
		}	
	}

	// Represent the sets using bit vectors
	int S1[n], S2[n];
	for (int i = 0; i < n; i++) {
		S1[i] = 0, S2[i] = 0;
		for (int j = 0; j < n1; j++) {
			if (U[i] == set1[j]) {
				S1[i] = 1;
				break;
			}
		}
		for (int j = 0; j < n2; j++) {
			if (U[i] == set2[j]) {
				S2[i] = 1;
				break;
			}
		}
	}

	// Perform Union
	int setUnion[n];
	for (int i = 0; i < n; i++) {
		if (S1[i] == 1 || S2[i] == 1)
			setUnion[i] = 1;
		else
			setUnion[i] = 0;
	}

	// Perform Intersection
	int setIntersection[n];
	for (int i = 0; i < n; i++) {
		if (S1[i] == 1 && S2[i] == 1)
			setIntersection[i] = 1;
		else
			setIntersection[i] = 0;
	}

	// Print the sets
	printf("U    : ");
	for (int i = 0; i < n; i++)
		printf("%d ", U[i]);
	printf("\nSet 1: ");
	for (int i = 0; i < n; i++)
		printf("%d ", S1[i]);
	printf("\nSet 2: ");
	for (int i = 0; i < n; i++)
		printf("%d ", S2[i]);
	printf("\nS1uS2: ");
	for (int i = 0; i < n; i++)
		printf("%d ", setUnion[i]);
	printf("\nS1nS2: ");
	for (int i = 0; i < n; i++)
		printf("%d ", setIntersection[i]);
	printf("\n");
}


// Check whether a value is present in an array: Linear Search
int isPresent(int arr[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value)
			return 1;
	}
	return 0;
}







