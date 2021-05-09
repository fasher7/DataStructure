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

void printArr(int *arr, int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

void printPathsHelper(node *n, int *arr, int c)
{
    if (n == nullptr)
    {
        return;
    }
    arr[c] = n->data;
    c = c + 1;
    if (n->left == nullptr && n->right == nullptr)
    {
        printArr(arr, c);
    }
    printPathsHelper(n->left, arr, c);
    printPathsHelper(n->right, arr, c);
}

void printPaths(node *n)
{
    int *arr = new int[countNodes(n)];
    printPathsHelper(n, arr, 0);
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
    printPaths(p);
    return 0;
}
