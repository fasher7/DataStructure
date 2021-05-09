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

int countNodes(node *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(n->left) + countNodes(n->right);
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
    cout << countNodes(p);
    return 0;
}
