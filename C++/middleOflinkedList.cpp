#include <cstddef>
#include <vector>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

// SINGLY-LINKED LIST DATA STRUCTURE
// =================================
// A linked list is a linear data structure where elements are stored in nodes.
// Each node contains:
//   1. data (value) - in our case, an integer (int val)
//   2. pointer to next node - stores the memory address of the next node
//
// Unlike arrays, linked lists are not stored contiguously in memory.
// Each node can be anywhere in memory, and we "link" them using pointers.
//
// Visual representation:
//   [val=1|next] -> [val=2|next] -> [val=3|next] -> null
//    node A         node B         node C
//
// SYNTAX EXPLANATION:
//   - struct: defines a custom data type (like a class in C++)
//   - ListNode*: pointer to a ListNode object (stores memory address)
//   - nullptr: represents a null pointer (no memory address, end of list)
//   - ListNode(): default constructor - creates node with val=0, next=null
//   - ListNode(int x): constructor - creates node with specific value
//   - ListNode(int x, ListNode* next): constructor - creates node with value and next pointer

struct ListNode {
  int val;                 // stores the integer value
  ListNode* next;          // pointer to the next node in the list
  
  // Default constructor: creates node with 0 and no next
  ListNode() : val(0), next(nullptr) {}
  
  // Constructor with value: creates node with specific value
  ListNode(int x) : val(x), next(nullptr) {}
  
  // Constructor with value and next: creates node and links it
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};

// ===== HELPER FUNCTIONS FOR TESTING =====

// Create a linked list from a vector of integers
// vector<int> = dynamic array that can grow/shrink
ListNode* createList(const vector<int>& values) {
  if (values.empty()) return nullptr;  // empty vector = no list
  
  ListNode* head = new ListNode(values[0]);  // create first node
  ListNode* current = head;                  // pointer to last node
  
  // Loop through remaining values and add nodes
  for (size_t i = 1; i < values.size(); i++) {
    current->next = new ListNode(values[i]);  // create new node and link
    current = current->next;                  // move to new node
  }
  
  return head;
}

// Convert linked list back to vector (for easy comparison in tests)
vector<int> listToVector(ListNode* head) {
  vector<int> result;
  ListNode* current = head;
  
  // Traverse until we reach the end (nullptr)
  while (current != nullptr) {
    result.push_back(current->val);  // add value to vector
    current = current->next;         // move to next node
  }
  
  return result;
}

// Free memory to prevent memory leaks
void freeList(ListNode* head) {
  while (head != nullptr) {
    ListNode* temp = head;    // save current node
    head = head->next;        // move to next
    delete temp;              // delete saved node
  }
}

// ===== TEST CASES =====

// TEST_CASE is doctest macro - creates a named test block
TEST_CASE("Odd number of nodes") {
  Solution sol;
  
  // Create list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode* head = createList({1, 2, 3, 4, 5});
  
  // Get middle node
  ListNode* middle = sol.middleNode(head);
  
  // CHECK verifies the condition is true (doctest macro)
  CHECK(middle->val == 3);  // middle should be 3
  
  freeList(head);  // clean up memory
}

TEST_CASE("Even number of nodes - returns second middle") {
  Solution sol;
  
  // Create list: 1 -> 2 -> 3 -> 4
  ListNode* head = createList({1, 2, 3, 4});
  
  ListNode* middle = sol.middleNode(head);
  
  // For even length, returns second middle (3, not 2)
  CHECK(middle->val == 3);
  
  freeList(head);
}

TEST_CASE("Single node") {
  Solution sol;
  
  ListNode* head = createList({1});
  
  ListNode* middle = sol.middleNode(head);
  
  CHECK(middle->val == 1);
  
  freeList(head);
}

TEST_CASE("Two nodes - returns second node") {
  Solution sol;
  
  ListNode* head = createList({1, 2});
  
  ListNode* middle = sol.middleNode(head);
  
  CHECK(middle->val == 2);
  
  freeList(head);
}

TEST_CASE("Larger odd list") {
  Solution sol;
  
  ListNode* head = createList({1, 2, 3, 4, 5, 6, 7});
  
  ListNode* middle = sol.middleNode(head);
  
  // 7 nodes, middle is 4th node (value 4)
  CHECK(middle->val == 4);
  
  freeList(head);
}

TEST_CASE("Larger even list") {
  Solution sol;
  
  ListNode* head = createList({10, 20, 30, 40, 50, 60});
  
  ListNode* middle = sol.middleNode(head);
  
  // 6 nodes, second middle is 4th node (value 40)
  CHECK(middle->val == 40);
  
  freeList(head);
}
