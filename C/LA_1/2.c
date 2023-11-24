/*
    2) Design the logic to remove the duplicate elements from an Array and after the
    deletion the array should contain the unique elements.
*/

#include <stdio.h>

#define MAX_SIZE 100

// Function to remove duplicates from the array
int removeDuplicates(int arr[], int size)
{
    int i, j, k;

    for (i = 0; i < size; ++i)
    {
        for (j = i + 1; j < size;)
        {
            // If duplicate found, shift elements to fill the gap
            if (arr[i] == arr[j])
            {
                for (k = j; k < size - 1; ++k)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
            }
            else
            {
                j++;
            }
        }
    }

    return size;
}

// Function to display the array
void displayArray(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[MAX_SIZE];
    int size;

    // Input size and elements of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n\tArray before removal of Duplicate Elements :- ");
    displayArray(array, size);
    // Remove duplicates
    size = removeDuplicates(array, size);
    printf("\n\tArray before removal of Duplicate Elements :- ");
    // Display the array after removing duplicates
    displayArray(array, size);

    return 0;
}