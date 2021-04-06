#include <iostream>
using namespace std;

struct node
{
    int val = 0;
    node* next = nullptr;
};

void printList(node* n)
{
    while (n != nullptr)
    {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

void addFront(node*& head, int val)
{
    if (head == nullptr)
    {
        node *n = new node;
        n->val = val;
        head = n;
    }
    else
    {
        node *n = new node;
        n->val = val;
        n->next = head;
        head = n;
    }
}

void addBack(node*& n, int data)
{
    if (n == nullptr)
    {
        n = new node;
        n->val = data;
    }
    else
    {
        node* current = n;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        node* p = new node;
        p->val = data;
        current->next = p;
    }
}
int removeFront(node*& head)
{
    if (head == nullptr)
    {
        return -1000;
    }
    else
    {
        node* j = head;

        int x = j->val;
        head = head->next;
        delete j;

        return x;
    }
}
int removeBack(node*& head)
{
    if (head == nullptr)
    {
        return -1000;
    }
    if (head->next == nullptr)
    {
        node* j = head;
        int x = j->val;
        head = head->next;
        delete j;
        return x;
    }
    node* current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    node* j = current->next;
    current->next = current->next->next;
    int x = j->val;
    delete j;
    return x;
}

int main()
{
    node* head = nullptr;
    // here only working with 2 functions except with 4
    // other 2 can be used as well
    addBack(head, 10);
    addBack(head, 20);
    addBack(head, 30);
    addBack(head, 40);
    printList(head);
    cout << removeBack(head) << endl;
    printList(head);
    cout << removeBack(head) << endl;
    printList(head);
    cout << removeBack(head) << endl;
    printList(head);
    cout << removeBack(head) << endl;
    printList(head);
    cout << removeBack(head) << " Empty List";

    return 0;
}
