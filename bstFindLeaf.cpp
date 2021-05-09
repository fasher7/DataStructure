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

void printLeaf(node *n)
{
    if (n == nullptr)
    {
        return;
    }
    else if (n->left == nullptr && n->right == nullptr)
    {
        cout << n->data << " ";
    }
    printLeaf(n->left);
    printLeaf(n->right);
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
    printLeaf(p);

    return 0;
}
