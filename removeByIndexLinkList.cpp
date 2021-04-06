#include <iostream>
using namespace std;

struct node
{
    int val = 0;
    node* next = nullptr; 
};

void addValue(node*& n, int data)
{
    if (n == nullptr)
    {
        n = new node;
        n -> val = data;
    }
    else
    {
        node* current = n;
        while (current -> next != nullptr)
        {
            current = current -> next;
        }
        node* p = new node;
        p -> val = data;
        current -> next = p;
    }
    return;
}

void removeValByIndx(node*& sll, int index)
{
    if (index == 0)
    {
        node* j = sll;
        sll = sll -> next;
        delete j;
    }

    else
    {
        node* current = sll;
        for (int i = 0; i < index - 1; ++i)
        {
            current = current -> next;
        }
        node* j = current -> next;
        current -> next = current -> next -> next;
    }
}

void printList(node* n)
{
    while (n != nullptr)
    {
        cout << n -> val << " ";
        n = n -> next;
    }
    cout << endl;
}

int main()
{
    node* sll = nullptr;
    addValue (sll, 10);  // 0
    addValue (sll, 20);  // 1
    addValue (sll, 30);  // 2 
    addValue (sll, 40);  // 3 - 4th index
    addValue (sll, 50);  // 4
    addValue (sll, 60);  // 5 
    printList(sll);
    removeValByIndx(sll, 3);  // removing 40
    printList(sll);

    return 0;   
}
