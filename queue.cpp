#include <iostream>
using namespace std;

struct node
{
    int val = 0;
    node *next = nullptr;
};

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

int main()
{
    node *myQueue = nullptr;
    enqueueElement(myQueue, 10);
    enqueueElement(myQueue, 20);
    enqueueElement(myQueue, 30);
    enqueueElement(myQueue, 40);
    enqueueElement(myQueue, 50);
    enqueueElement(myQueue, 60);
    enqueueElement(myQueue, 70);

    cout << numElm(myQueue) << endl;
    return 0;
}
