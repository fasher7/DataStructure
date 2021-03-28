#include <iostream>
using namespace std;

struct node
{
    int data = 0;
};

int main()
{
    node* a = nullptr;
    a = new node;
    a -> data = 123;

    cout << a << endl; 
    cout << a -> data << endl;
    delete[] a;

    return 0;
}
