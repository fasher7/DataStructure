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
        n->val = data;
    }
    else
    {
        node* current = n;
        while(current -> next != nullptr)
        {
            current = current->next;
        }
    node* p = new node;
    p -> val = data;
    current -> next = p;
    }
}

void addValueByInd(node*& sll, int data, int index)
{
    if (index == 0)
    {
        node* n = new node;
        n -> val = data;
        n -> next = sll;
        sll = n;
    }
    else
    {
        node* current = sll;
        for (int i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }
        node* n = new node;
        n -> val = data;
        n -> next = current -> next;
        current -> next = n;
    }
}

void printList(node* n)
{
    while (n != nullptr)
    {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    node* sll = nullptr;
    addValue(sll, 10); //0
    addValue(sll, 20); //1
    addValue(sll, 30); //2 - 2nd index
    addValue(sll, 40); //3
    addValue(sll, 50); //4
    addValue(sll, 60); //5
    printList(sll);
    addValueByInd(sll, 112, 2); // adding 112 before 30
    printList(sll);

    return 0;
}
