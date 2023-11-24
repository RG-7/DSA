/*
 * 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
 *  if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
 *  of inversions in an array.
 */

#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            // If arr[i] > arr[j], it means an inversion
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; ++i)
    {
        arr[i] = temp[i];
    }

    return count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int count = 0;

    if (left < right)
    {
        int mid = (left + right) / 2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }

    return count;
}

int countInversions(int arr[], int n)
{
    int *temp = (int *)malloc(n * sizeof(int));
    int count = mergeSort(arr, temp, 0, n - 1);
    free(temp);
    return count;
}

void inputFun()
{
    int *a, col;
    printf("\nEnter the value of Column: ");
    scanf("%d", &col);

    a = (int *)malloc(col * sizeof(int));

    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < col; i++)
    {
        scanf("%d", &a[i]);
    }

    int count = countInversions(a, col);
    printf("\nTotal Number of inversions is %d\n", count);

    free(a);
}

int main()
{
    inputFun();
    return 0;
}