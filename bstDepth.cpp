#include <iostream>
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

int depth(node *n, int v)
{
    if (n == nullptr)
    {
        return -1000;
    }
    else if (n->data == v)
    {
        return 0;
    }
    else if (v > n->data)
    {
        return depth(n-> right, v) + 1;
    }
    else
    {
        return depth (n-> left, v) + 1;
    }
}

int main()
{
    node *p = nullptr;
    insertVal(p, 13);
    insertVal(p, 10);
    insertVal(p, 24);
    insertVal(p, 8);
    insertVal(p, 7);
    insertVal(p, 26);
    insertVal(p, 25);
    printTree(p);
    cout << endl;
    cout << depth (p,7) << endl;
    cout << depth (p,8) << endl;
    cout << depth (p,24) << endl;

    return 0;
}
