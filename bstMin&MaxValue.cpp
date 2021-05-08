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

int minVal(node *n)
{
    if (n == nullptr)
    {
        return -10000;
    }
    else if (n->left == nullptr)
    {
        return n->data;
    }
    else
        return minVal(n->left);
}

int maxVal(node *n)
{
    if (n == nullptr)
    {
        return -10000;
    }
    else if (n->right == nullptr)
    {
        return n->data;
    }
    else
        return maxVal(n->right);
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
    insertVal(p, 16);
    insertVal(p, 10);
    insertVal(p, 27);
    insertVal(p, 2);
    insertVal(p, 14);
    insertVal(p, 13);
    insertVal(p, 11);
    insertVal(p, 30);
    insertVal(p, 50);
    insertVal(p, 36);
    printTree(p);
    cout << endl;
    cout << minVal(p) << endl;
    cout << maxVal(p) << endl;

    return 0;
}
