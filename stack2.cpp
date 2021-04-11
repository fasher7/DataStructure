#include <iostream>
using namespace std;

struct node
{
    int val = 0;
    node *next = nullptr;
};

void pushElement(node *&n, int data)
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
    }
}

int popElement(node *&head)
{
    if (head == nullptr)
    {
        return -1000;
    }
    if (head->next == nullptr)
    {
        node *j = head;
        int x = j->val;
        head = head->next;
        delete j;
        return x;
    }
    node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    node *j = current->next;
    current->next = current->next->next;
    int x = j->val;
    delete j;
    return x;
}

int main()
{
    node *myStack = nullptr;

    pushElement(myStack, 10);
    pushElement(myStack, 20);
    pushElement(myStack, 30);
    pushElement(myStack, 40);

    cout << popElement(myStack) << endl;
    cout << popElement(myStack) << endl;
    cout << popElement(myStack) << endl;
    cout << popElement(myStack) << endl;
    cout << popElement(myStack) << endl;

    return 0;
}
