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

int height(node *n)
{
    if (n == nullptr)
    {
        return -1;
    }
    else
    {
        int r = height(n->right);
        int l = height(n->left);
        if (r > l)
        {
            return r + 1;
        }
        else
            return l + 1;
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
    cout << height(p);
    return 0;
}
