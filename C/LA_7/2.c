/*
    A slightly improved selection sort – We know that selection sort algorithm takes the minimum on every pass on the array, and place it at its correct position. 
    The idea is to take also the maximum on every pass and place it at its correct position. So in every pass, we keep track of both maximum and minimum and array becomes 
    sorted from both ends. Implement this logic.
*/

#include <stdio.h>

void bidirectionalSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left, maxIndex = right;

        // Find the minimum and maximum in the unsorted part
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            } else if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // Swap the minimum with the leftmost element
        if (minIndex != left) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[left];
            arr[left] = temp;
        }

        // If the maximum was at the leftmost position, update its index
        if (maxIndex == left) {
            maxIndex = minIndex;
        }

        // Swap the maximum with the rightmost element
        if (maxIndex != right) {
            int temp = arr[maxIndex];
            arr[maxIndex] = arr[right];
            arr[right] = temp;
        }

        // Move the boundaries towards the center
        left++;
        right--;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bidirectionalSelectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
