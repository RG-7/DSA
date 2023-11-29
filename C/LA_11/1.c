#include <stdio.h>
#include <limits.h>

void mostFrequent(int arr[], int n) {
    int maxCount = 0, res = -1;
    int hash[10000] = {0}; // Create a hash table with 10000 cells, all initialized to 0

    // Store counts of all elements in the hash table
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // Iterate over the hash table and find the element with maximum count
    for (int i = 0; i < 10000; i++) {
        if (maxCount < hash[i]) {
            maxCount = hash[i];
            res = i;
        }
    }

    printf("Most frequent element is %d\n", res);
}

int main() {
    printf("\n");
    int arr[] = {1, 5, 2, 1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mostFrequent(arr, n);

    printf("\n");
    return 0;
}
