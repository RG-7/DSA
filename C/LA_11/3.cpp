#include <iostream>
#include <unordered_set>

void findUnique(const int arr1[], const int arr2[], int n1, int n2) {
    std::unordered_set<int> hashSet(arr2, arr2 + n2);

    for (int i = 0; i < n1; i++) {
        if (hashSet.find(arr1[i]) == hashSet.end()) {
            std::cout << arr1[i] << " ";
        }
    }

    std::cout << "\n";
}

int main() {
    std::cout << "\n";
    int arr1[] = {1, 5, 2, 1, 3, 2, 1};
    int arr2[] = {1, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findUnique(arr1, arr2, n1, n2);

    std::cout << "\n";
    return 0;
}
