/*
    ADDITIONAL QUESTION 2
    Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The operations allowed on queue are :
        (i) enqueue()
        (ii) dequeue()
        (iii) isEmpty()

    Example 1 : -
        Input : A queue with elements
            11  5  4  21
        Output : Modified queue with following elements
            4 5 11 21
    Example 2 : -
        Input : A queue with elements
            3  2  1  2
        Output : Modified queue with following elements
            1 2 2 3
*/

#include <stdio.h>

// Function to check if the queue is empty
int isEmpty(int *q, int size)
{
    return size == 0;
}

// Function to find the index of the minimum element from the front to the given index
int findMinIndex(int *q, int size, int endIndex)
{
    int min_index = 0;
    int min_val = q[0];
    for (int i = 1; i <= endIndex; i++)
    {
        if (q[i] < min_val)
        {
            min_index = i;
            min_val = q[i];
        }
    }
    return min_index;
}

// Function to move 'n' elements from the front of the queue to the rear
void moveToFront(int *q, int size, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = q[0];
        for (int j = 0; j < size - 1; j++)
        {
            q[j] = q[j + 1];
        }
        q[size - 1] = temp;
    }
}

// Function to insert an element into a sorted queue
void insertSorted(int *q, int size, int element)
{
    if (isEmpty(q, size) || element >= q[size - 1])
    {
        q[size++] = element;
        return;
    }

    int temp = q[size - 1];
    for (int i = size - 2; i >= 0 && q[i] > element; i--)
    {
        q[i + 1] = q[i];
    }
    q[size - 1] = element;
    q[size++] = temp;
}

// Function to sort the given queue
void sortQueue(int *q, int size)
{
    for (int i = 1; i <= size; i++)
    {
        int min_index = findMinIndex(q, size, size - i);
        moveToFront(q, size, min_index);
        insertSorted(q, size, q[size - 1]);
    }
}

// Function to display the elements of the queue
void displayQueue(int *q, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main()
{
    int queue[] = {11, 5, 4, 21};
    int size = sizeof(queue) / sizeof(queue[0]);

    // Sort the queue
    sortQueue(queue, size);

    // Display the sorted queue
    printf("Sorted Queue: ");
    displayQueue(queue, size);

    return 0;
}