#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to find the middle of the linked list
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != nullptr) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != nullptr) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

// Function to perform merge sort on the linked list
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    // Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both left and right halves
    Node* result = merge(left, right);

    return result;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to add a new node to the end of the linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    Node* head = nullptr;

    // Add elements to the linked list
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);

    cout << "Given Linked List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
