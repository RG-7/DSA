/*
 * 3) Design the Logic to Find a Missing Number in a Sorted Array.
 */

#include <stdio.h>

// missing number function
void missingNumber(int *a, int length)
{
    int end = length - 1;
    int start = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == mid + 1)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    printf("\nThe missing Number is : %d\n", a[start] - 1);
}
// printing array function
void printArray(int *a, int length)
{
    int col = length;
    for (int i = 0; i < col; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(a[0]);
    printf("\n\tPrinting Array with missing number is :- \n\t");
    printArray(a, length);
    missingNumber(a, length);
}