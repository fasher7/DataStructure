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

bool findVal(node *n, int val)
{
    if (n == nullptr)
    {
        return false;
    }
    else if (n->data == val)
    {
        return true;
    }
    else if (val > n->data)
    {
        return findVal(n->right, val);
    }
    else
    {
        return findVal(n->left, val);
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

int main()
{
    node *p = nullptr;
    insertVal(p, 10);
    insertVal(p, 20);
    insertVal(p, 5);
    insertVal(p, 3);
    insertVal(p, 4);
    insertVal(p, 12);
    insertVal(p, 25);
    printTree(p);
    cout << endl
         << findVal(p, 6); // for 6 it returned 0, for 12 it will return 1 

    return 0;
}
