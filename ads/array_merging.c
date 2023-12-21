#include <stdio.h>


void main()
{
    // Read the sizes of the arrays
    int n1, n2;
    printf("Enter the size of the arrays: ");
    scanf("%d%d", &n1, &n2);

    int arr1[n1], arr2[n2];

    // Read the array elements
    printf("Enter the elements in array 1: ");
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    
    printf("Enter the elements in array 2: ");
    for(int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    

    // Merge the arrays
    int merged[n1 + n2];
    for (int i = 0; i < n1 + n2; i++)
    {
        if (i < n1)
            merged[i] = arr1[i];
        else
            merged[i] = arr2[i - n1];
    }

    // Display
    for (int i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);
    printf("\n");
}
