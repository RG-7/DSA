#include <stdio.h>
#include <stdbool.h>

void checkSum(int arr[], int n, int x) {
    bool hash[10000] = {false}; // Create a hash set with 10000 cells, all initialized to false

    // Iterate over the array and build the hash set
    for (int i = 0; i < n; i++) {
        hash[arr[i]] = true;
    }

    // Iterate over the array and check for the existence of a pair with the sum x
    for (int i = 0; i < n; i++) {
        int complement = x - arr[i];
        if (complement >= 0 && complement < 10000 && hash[complement]) {
            printf("Pair with sum %d exists\n", x);
            return;
        }
    }

    printf("Pair with sum %d does not exist\n", x);
}

int main() {
    printf("\n");
    int arr[] = {1, 5, 2, 1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    checkSum(arr, n, x);

    printf("\n");
    return 0;
}
