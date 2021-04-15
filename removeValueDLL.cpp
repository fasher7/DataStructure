#include <iostream>
using namespace std;

struct node
{
    int val = 0;
    node *prev = nullptr;
    node *next = nullptr;
};

void addValue(node *&n, int data)
{
    if (n == nullptr)
    {
        n = new node;
        n->val = data;
    }
    else
    {
        node *current = n;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        node *p = new node;
        p->val = data;

        current->next = p;
        p->prev = current; 
    }
}

void removeValue(node *&n, int data)
{
    if (n == nullptr)
    {
        return;
    }
    while (n->val == data)
    {
        node *j = n;
        n = n->next;
        if (n != nullptr)
        {
            n->prev = nullptr; 
        }
        delete j;
        if (n == nullptr)
        {
            return;
        }
    }

    node *current = n;
    while (current->next != nullptr)
    {
        if (current->next->val == data)
        {
            node *j = current->next;
            current->next = current->next->next;
            if (current->next != nullptr)
            {
                current->next->prev = current; 
            }
            delete j;
        }
        else
        {
            current = current->next;
        }
    }
}

void printList(node *n)
{
    if (n == nullptr)
    {
        return;
    }
    while (n->next != nullptr)
    {
        cout << n->val << " ";
        n = n->next;
    }
    cout << n->val << endl;

    while (n->prev != nullptr)
    {
        cout << n->val << " ";
        n = n->prev;
    }
    cout << n->val << endl;

    cout << endl;
}

int main()
{
    node *p = nullptr;

    //use different numbers to understand other bits
    addValue(p, 10);
    addValue(p, 10);

    printList(p);
    removeValue(p, 10);
    printList(p);

    return 0;
}
