#include <iostream>
using namespace std;

struct node
{
    int data = 0;
    node *next = nullptr;
    node(int v)
    {
        data = v;
    }
};

int main()
{
    node *a1 = new node(1);
    node *a2 = new node(2);
    a1->next = a2;
    node *b1 = new node(10);
    node *b2 = new node(20);
    b1->next = b2;
    node *c1 = new node(100);

    node *adjList[3];
    adjList[0] = a1;
    adjList[1] = b1;
    adjList[2] = c1;

    for (int i = 0; i < 3; ++i)
    {
        node *x = adjList[i];
        while (x != nullptr)
        {
            cout << x->data << " ";
            x = x->next;
        }
        cout << endl;
    }

    return 0;
}
