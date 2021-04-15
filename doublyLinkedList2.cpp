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
        p->prev = current; //only change
    }
}

void printList(node *n)
{
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
    addValue(p, 10);
    addValue(p, 20);
    addValue(p, 30);
    addValue(p, 40);
    addValue(p, 50);
    printList(p);
    return 0;
}
