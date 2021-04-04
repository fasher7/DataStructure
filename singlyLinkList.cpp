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
        cout << "n: " << n << endl;
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

void printList(node* n)
{
    while (n != nullptr)
    {
        cout << n -> val << " " << n << endl;
        n = n -> next;
    }
    cout << endl;
}

int main()
{
    // singly link list
    node* sll = nullptr;
    addValue(sll, 10); // node*&n = sll
    cout << sll << endl;
    addValue(sll, 20);
    cout << sll << endl;    
    addValue(sll, 30); 
    cout << sll << endl;
    addValue(sll, 40);
    cout << sll << endl;
    addValue(sll, 50);  
    cout << sll << endl; 
    // sll's address doesn't change at all
    printList(sll);
    return 0;   
}
