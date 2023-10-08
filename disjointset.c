#include <stdio.h>
#include <stdlib.h>

#define n 10


int Parent[n];
int Rank[n];

int Find(int x);
int Union(int x, int y);
int display();


void main()
{
	// Initially each node is its own parent i.e. parent[i] = i and rank of every node is 0
	for (int i = 0; i < n; i++)
	{
		Parent[i] = i;
		Rank[i] = 0;
	}
	
	while (1) {
		int choice;
		printf("Enter 1 to find the parent of an element, 2 to merge two sets, 3 to display, or 5 to exit: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				int element;
				printf("Element: ");
				scanf("%d", &element);
				if (element < n)
					printf("%d\n", Find(element));
				break;
			case 2:
				int x, y;
				printf("Enter the subsets to merge: ");
				scanf("%d%d", &x, &y);
				if (x < n && y < n)
				{
					Union(x, y);
					printf("Success!\n");
				}		
				break;
			case 3:
				display();
				break;
			case 5:
				exit(0);
			default:
				break;
		}
	}
}


int Find(int x)
{
	if (Parent[x] == x)
		return x;

	// Path compression
	int root = Find(Parent[x]);
	Parent[x] = root;
	return root;
}


int Union(int u, int v)
{
	// Get the parent of each element
	u = Find(u);
	v = Find(v);
	
	// If they belong to different subsets
	if (u != v)
	{
		// Attach the tree with lesser rank to the tree with greater rank
		if (Rank[u] < Rank[v])
			Parent[u] = v;
		else
			Parent[v] = u;
		
		// If both trees have the same depth (we have already attached it to u)
		if (Rank[u] == Rank[v])
			Rank[u]++;
	}
}


int display()
{
	// Initialise a set to store all the elements 
	int sets[n];
	for (int i = 0; i < n; i++)
		sets[i] = i;
		
	// Sort the set in the order of their root (Bubble sort)
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (Find(sets[j]) > Find(sets[j + 1]))
			{
				// Swap
				int temp = sets[j];
				sets[j] = sets[j + 1];
				sets[j + 1] = temp;
			}
		}
	}
	
	// Display the disjoint set
	int prevParent = Find(sets[0]);
	printf("( ");
	for (int i = 0; i < n; i++)
	{
		int par = Find(sets[i]);
		if (i != 0 && par != prevParent)
			printf(")( ");
		printf("%d ", sets[i]);
		prevParent = par;
	}
	printf(")\n");
}


