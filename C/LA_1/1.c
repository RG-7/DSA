/*
    1) Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
    ——MENU——-
    1.CREATE
    2.DISPLAY
    3.INSERT
    4.DELETE
    5.LINEAR SEARCH
    6.EXIT
*/
#include <stdio.h>

#define MAX_SIZE 100

void createArray(int arr[], int *size)
{
    printf("Enter the size of the array: ");
    scanf("%d", size);

    printf("Enter elements of the array:\n");
    for (int i = 0; i < *size; ++i)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array created successfully.\n");
}

void displayArray(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size)
{
    int element, position;

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position to insert (0-indexed): ");
    scanf("%d", &position);

    if (position >= 0 && position <= *size)
    {
        for (int i = *size; i > position; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        (*size)++;
        printf("Element inserted successfully.\n");
    }
    else
    {
        printf("Invalid position. Insertion failed.\n");
    }
}

void deleteElement(int arr[], int *size)
{
    int element, found = 0;

    printf("Enter the element to delete: ");
    scanf("%d", &element);

    for (int i = 0; i < *size; ++i)
    {
        if (arr[i] == element)
        {
            for (int j = i; j < *size - 1; ++j)
            {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            found = 1;
            printf("Element deleted successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Element not found in the array. Deletion failed.\n");
    }
}

void linearSearch(int arr[], int size)
{
    int element, found = 0;

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == element)
        {
            printf("Element %d found at index %d.\n", element, i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element %d not found in the array.\n", element);
    }
}

int main()
{
    int array[MAX_SIZE];
    int size = 0;
    int choice;

    while (1)
    {
        printf("\n------MENU------\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createArray(array, &size);
            break;
        case 2:
            displayArray(array, size);
            break;
        case 3:
            insertElement(array, &size);
            break;
        case 4:
            deleteElement(array, &size);
            break;
        case 5:
            linearSearch(array, size);
            break;
        case 6:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
