/*
 * 1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time 
 *  complexity of Ο(log n) in comparison to the Linear Search.
*/

#include <stdio.h>

// input function
void input(int *array,int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\n");
}
// binary search
void binary(int *array, int key,int size)
{
    int start = 0, end = size - 1;
    int found = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (array[mid] == key)
        {
            printf("\n%d is found at index %d\n", key, mid);
            found = 1;
            break;
        }
        else if (array[mid] > key)
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }
    if (!found)
    {
        printf("\n\t----Not Found------\n");
    }
}
// linear Search
void linear(int *array, int key,int size)
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            printf("\n%d is found at index %d\n\n", key, i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\n\t----Not FOund----\n\n");
    }
}

int main()
{
    int array[10];
    int array1[10];
    int num;
    printf("\n\t------- Enter the Elements of array(sorted array) ---------\n");
    input(array,10);
    printf("---Enter the number you want to search :- ");
    scanf("%d", &num);
    printf("\n\t------ Performing Binary Search Algorith --------\n");
    binary(array, num,10);

    // linear search
    printf("\n\t------- Enter the Elements of array ---------\n");
    input(array1,10);
    printf("---Enter the number you want to search :- ");
    scanf("%d", &num);
    printf("\n\t-------- Performing Linear Search Algorith ---------\n");
    linear(array1, num,10);
}