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
    printTree(n->left);  //to see big to small just use n->right first
    cout << n->data << " ";
    printTree(n->right);
}

int main()
{
    node *p = nullptr;
    insertVal(p, 10);
    insertVal(p, 20);
    insertVal(p, 5);
    insertVal(p, 21);
    insertVal(p, 12);
    insertVal(p, -2);
    printTree(p);

    return 0;
}
