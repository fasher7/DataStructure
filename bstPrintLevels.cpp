#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data = 0;
    node *left = nullptr;
    node *right = nullptr;
};

void insertVal(node *&n, int val)
{
    if (n == nullptr)
    {
        n = new node;
        n->data = val;
    }
    else if (val > n->data)
    {
        insertVal(n->right, val);
    }
    else if (val < n->data)
    {
        insertVal(n->left, val);
    }
}

void printTree(node *n)
{
    if (n == nullptr)
    {
        return;
    }
    cout << n->data << " ";
    printTree(n->left);
    printTree(n->right);
}

void printLevels(node *n)
{
    queue<node *> q;
    q.push(n);
    int sz = q.size();

    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        sz = sz - 1;
        cout << p->data << " ";

        node *leftChild = p->left;
        node *rightChild = p->right;

        if (leftChild != nullptr)
        {
            q.push(leftChild);
        }
        if (rightChild != nullptr)
        {
            q.push(rightChild);
        }
        if (sz == 0)
        {
            cout << endl;
            sz = q.size();
        }
    }
}

int main()
{
    node *p = nullptr;
    insertVal(p, 12);
    insertVal(p, 10);
    insertVal(p, 15);
    insertVal(p, 8);
    insertVal(p, 14);
    insertVal(p, 18);
    printTree(p);
    cout << endl;
    printLevels(p);
    return 0;
}
