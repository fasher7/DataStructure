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

void removeVal(node *&n, int v)
{
    if (n == nullptr)
    {
        return;
    }
    else if (v > n->data)
    {
        removeVal(n->right, v);
    }
    else if (v < n->data)
    {
        removeVal(n->left, v);
    }
    else
    {
        if (n->left == nullptr && n->right == nullptr)
        {
            node *j = n;
            n = nullptr;
            delete j;
        }
        else if (n->left == nullptr)
        {
            n = n->right;
        }
        else if (n->right == nullptr)
        {
            n = n->left;
        }
        else
        {
            int minV = minVal(n->right);
            n->data = minV;
            removeVal(n->right, minV);
        }
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
    removeVal(p, 10);
    printTree(p);

    return 0;
}
