// Pass-by-value
// pass-by-pointer
// pass-by-reference

#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

void insertHead(ListNode *head, int value) {
    
}

void insertTail(ListNode *head, int value) {
    
}

// 0. Edge case
// 1. Traverse to the node (keep the previous node)
// 2. Remove the node
// 3. Update the previous node

int popLast(ListNode *head) {
    // 0. Edge case
    if (head == nullptr)
        throw "Error: Cannot pop from an empty list";
    
    // 1. Traverse to the node before the tail
    ListNode* current = head;
    ListNode* prev = nullptr;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    ListNode* tail = current; 
    ListNode* prev_tail = prev;

    // 2. Remove the tail
    int value = current->value;
    delete tail;

    // 3. update prev_tail's next
    prev_tail->next = nullptr;

    return value;
}

int popFirst(ListNode *head) {
    return 0;
}

ListNode* get(ListNode *head, int n) {
    // 0. Check edge case.
    //    a. head == nullptr
    //    b. n < 0
    if (n < 0 || head == nullptr) {
        return head;
    }

    // 1. Traverse to the relevant node.
    ListNode *ptr_current = head; // &a
    
    for (int i = 0; i < n; ++i) {
        ptr_current = ptr_current->next;
    }

    return ptr_current;
}

ListNode* getHead(ListNode *head) {
    return head;
}

ListNode* getTail(ListNode *head) {
    ListNode* ptr_current = head;
    while (ptr_current->next != nullptr) {
        ptr_current = ptr_current->next;
    }
    return ptr_current;
}

int pop(ListNode *head, size_t index) {
    // 0. Edge case
    if (head == nullptr)
        throw "Error: Cannot pop from an empty list";
    
    // 1. Traverse to the node at index
    ListNode* current = head;
    ListNode* prev = nullptr;
    size_t i = 0;
    while (current->next != nullptr && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (i != index)
        throw "Error: Reached end of list early";

    // 2. Remove the current node
    int value = current->value;
    ListNode *next = current->next;

    delete current;

    // 3. update prev's next
    prev->next = next;

    return value;
}

// Main operations:
//   head()                -> Return the first node
//   tail()                -> Return the last node
//   prepend(value)        -> Add a node in the beginning
//   append(value)         -> Add a node in the end
//   add(value, index)     -> Add a node at index
//   popHead()             -> Remove a node from the end
//   popTail()             -> Remove a node from the beginning
//   pop(index)            -> Remove a node at index

int main() {
    ListNode a, b, c, d;

    a.value = 100;
    b.value = 200;
    c.value = 300;
    d.value = 400;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = nullptr;

    ListNode *head = &a;
    ListNode *ptr_a = getHead(head); // &a;
    ListNode *ptr_b = getHead(head)->next; // &b
    ListNode *ptr_c = getHead(head)->next->next; // &c
    ListNode *ptr_d = getHead(head)->next->next->next; // &d

    // Traversal
    // cout << (getHead(head))->value << endl; // dereference and get member
    cout << getTail(head)->value << endl;

    cin.ignore();
    getchar();

    return 0;
}

// template <typename T>
// struct ListNode {
//     T value;
//     ListNode* next; 
// };

// template <typename T>
// void prepend(ListNode *head, T value) {
// ...
// }
