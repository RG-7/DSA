#include <iostream>
#include <unordered_set>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at the beginning of the linked list
void push(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

// Function to find the union and intersection of two linked lists
void findUnionIntersection(Node* list1, Node* list2, Node*& unionList, Node*& intersectionList) {
    std::unordered_set<int> hashSet;

    // Traverse the first list and insert elements into the hash set
    while (list1 != nullptr) {
        hashSet.insert(list1->data);
        list1 = list1->next;
    }

    // Traverse the second list
    while (list2 != nullptr) {
        // Insert unique elements into the union list
        if (hashSet.insert(list2->data).second) {
            push(unionList, list2->data);
        }

        // Insert common elements into the intersection list
        else {
            push(intersectionList, list2->data);
        }

        list2 = list2->next;
    }
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Node* unionList = nullptr;
    Node* intersectionList = nullptr;

    // Example data for the linked lists
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {30, 40, 50, 60, 70};

    // Populate the linked lists
    for (int i : arr1) {
        push(list1, i);
    }

    for (int i : arr2) {
        push(list2, i);
    }
    printf("\n");
    // Find union and intersection
    findUnionIntersection(list1, list2, unionList, intersectionList);

    // Print results
    std::cout << "Union list is: ";
    printList(unionList);

    std::cout << "Intersection list is: ";
    printList(intersectionList);

    printf("\n");
    return 0;
}
