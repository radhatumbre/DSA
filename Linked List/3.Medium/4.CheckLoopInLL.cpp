// brute    : keep hashmap which stores visited, if again visited return true if reached null return false;
// optimal  : tortoise hare method  (if both land at same spot cycle detected, if fast reaches null or next is null return false)

#include <iostream>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};

class Solution {
public:
    // Function to detect a loop in a linked
    // list using the Tortoise and Hare Algorithm
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast,
        // to the head of the linked list
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 2: Traverse the linked list with
        // the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow one step
            slow = slow->next;
            // Move fast two steps
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        // If fast reaches the end of the list,
        // there is no loop
        return false;
    }
};

// Main function to test the Solution
int main() {
    // Create a sample linked list
    // with a loop for testing
    
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third;

    // Create an instance of the Solution class
    Solution solution;

    // Check if there is a loop 
    // in the linked list
    if (solution.hasCycle(head)) {
        std::cout << "Loop detected in the linked list." << std::endl;
    } else {
        std::cout << "No loop detected in the linked list." << std::endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
