#include <iostream>
using namespace std;

struct node
{
    int val = 0;
    node *next = nullptr;
};

bool isEmpty(node*n)
{
    if(n == nullptr)
    {
        return true;
    }
    return false;
}

int numElm(node *n)
{
    int countNode = 0;
    while (n != nullptr)
    {
        countNode += 1;
        n = n->next;
    }
    return countNode;
}

void enqueueElement(node *&n, int data)
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

int dequeueElement(node *&head)
{
    if (head == nullptr)
    {
        return -1000;
    }
    else
    {
        node *j = head;

        int x = j->val;
        head = head->next;
        delete j;

        return x;
    }
}

int main()
{
    node *myQueue = nullptr;
    enqueueElement(myQueue, 10);
    enqueueElement(myQueue, 20);
    enqueueElement(myQueue, 30);
    enqueueElement(myQueue, 40);
    enqueueElement(myQueue, 50);
    enqueueElement(myQueue, 60);

    cout << numElm(myQueue) << endl;

    dequeueElement(myQueue);
    dequeueElement(myQueue);
    dequeueElement(myQueue);

    cout << numElm(myQueue) << endl;

    cout << "0 means NO & 1 means YES" << endl;
    cout << isEmpty(myQueue) << endl;

    return 0;
}
