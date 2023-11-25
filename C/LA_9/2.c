/*
    Implement priority queues using heaps.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a priority queue
struct PriorityQueue {
    int* heap;
    int capacity;
    int size;
};

// Function to create a new priority queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->heap = (int*)malloc(capacity * sizeof(int));
    return pq;
}

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain heap property (max heap)
void maxHeapify(struct PriorityQueue* pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->heap[left] > pq->heap[largest])
        largest = left;

    if (right < pq->size && pq->heap[right] > pq->heap[largest])
        largest = right;

    if (largest != i) {
        swap(&pq->heap[i], &pq->heap[largest]);
        maxHeapify(pq, largest);
    }
}

// Function to insert an element into the priority queue
void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full. Cannot insert.\n");
        return;
    }

    pq->heap[pq->size++] = value;

    int i = pq->size - 1;
    while (i > 0 && pq->heap[(i - 1) / 2] < pq->heap[i]) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the maximum element from the priority queue
int extractMax(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    if (pq->size == 1) {
        return pq->heap[--pq->size];
    }

    int root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    maxHeapify(pq, 0);

    return root;
}

// Function to get the maximum element from the priority queue without removing it
int getMax(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    return pq->heap[0];
}

// Function to print the elements of the priority queue
void printPriorityQueue(struct PriorityQueue* pq) {
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue(10);

    insert(pq, 10);
    insert(pq, 30);
    insert(pq, 20);
    insert(pq, 25);

    printPriorityQueue(pq);

    printf("Max element: %d\n", getMax(pq));

    printf("Extracted max element: %d\n", extractMax(pq));

    printPriorityQueue(pq);

    return 0;
}
