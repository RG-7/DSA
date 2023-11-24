/*
 * 2) Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent
 * elements if they are in wrong order. Code the Bubble sort with the following elements:
 *  _______________________________________________________________
 * |        |         |        |        |         |       |       |
 * |  64    |    34   |   25   |   12   |   22    |  11   |   90  |
 * |________|_________|________|________|_________|_______|_______|
 */

#include <stdio.h>

// bubble sort function
void bubbleSort(int *a, int row)
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < row - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
// input array fucntion
void inputArray(int *a, int row)
{
    printf("Enter the elemnts of array :- \n");
    for (int i = 0; i < row; i++)
    {
        scanf("%d", &a[i]);
    }
}
// printing arrya fucntion
void printArray(int *a, int row)
{
    for (int i = 0; i < row; i++)
    {
        printf( "%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[100];
    int row;
    printf("Enter the number of column : ");
    scanf("%d", &row);
    inputArray(a, row);
    printf("\n------Printing Array before sorting :-------- \n");
    printArray(a, row);
    bubbleSort(a, row);
    printf("\n------Printing Array before sorting :-------- \n");
    printArray(a, row);
}