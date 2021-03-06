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

void removeValue(node*& n, int data)
{
    if (n -> val == data)
    {
        node* j = n;
        n = n -> next;
        delete j;
    }
    else
    {
        node* current = n;
        while(current -> next != nullptr)
        {
            if(current -> next -> val == data)
            {
                node* j = current -> next;
                current -> next = current -> next -> next;
                delete j;
            }
            else 
            {
                current = current -> next;
            }
        }
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
    addValue(sll, 10); 
    addValue(sll, 20);
    addValue(sll, 30);
    addValue(sll, 40);
    addValue(sll, 50);
    addValue(sll, 60);
    printList(sll);
    removeValue(sll, 40);
    printList(sll);
    removeValue(sll, 10);
    printList(sll);
    return 0;   
}
