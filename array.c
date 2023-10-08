#include <stdio.h>
#include <stdlib.h>

int array[100];
int n;


void display();
int insertion();
int deletion();
int search();
int sort();


void main()
{
	// Read the array
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
	
	while (1) {
		int choice;
		printf("Enter 0 to display, 1 to insert, 2 to delete, 3 to search, 4 to sort or 5 to exit: ");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				display();
				break;
			case 1:
				insertion();
				break;
			case 2:
				deletion();
				break;
			case 3:
				search();
				break;
			case 4:
				sort();
				break;
			case 5:
				exit(0);
			default:
				break;
		}
	}
	
}


// Traverse through the array
void display()
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}


// Insert an element at a particular postion
int insertion()
{
	int position, element;
	printf("Position: ");
	scanf("%d", &position);

	if (position > n + 1)
		return 1;

	printf("Element: ");
	scanf("%d", &element);

	n++;
	for (int i = n - 1; i > position - 1; i--)
	{
		array[i] = array[i - 1];
	}
	array[position - 1] = element;
	return element;
}


// Delete an element from a particular position
int deletion()
{
	if (n == 0)
		return 1;
	int position;
	printf("Position: ");
	scanf("%d", &position);

	if (position > n)
		return 1;

	int element = array[position - 1];
	for (int i = position - 1; i < n; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
	return element;
}


// Linear Search
int search()
{
	int element;
	printf("Element: ");
	scanf("%d", &element);
	for (int i = 0; i < n; i++)
	{
		if (array[i] == element)
		{
			printf("Element %d found at Postion: %d\n", element, i + 1);
			return i;
		}
	}
	printf("Not found!\n");
	return 1;
}


// Bubble Sort
int sort()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	printf("Sorted!\n");
	return 0;
}

