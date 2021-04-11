#include <iostream>
using namespace std;

struct myStack
{
    int counter = 0;
    int *elements = new int[5];
};

void pushElement(myStack *&st, int x)
{
    st->elements[st->counter] = x;
    st->counter += 1;
}

int popElement(myStack *&st)
{
    st->counter -= 1;
    return st->elements[st->counter];
}

int main()
{
    myStack *s = new myStack;
    pushElement(s, 10);
    pushElement(s, 20);
    pushElement(s, 30);
    pushElement(s, 40);

    cout << popElement(s) << endl;
    cout << popElement(s) << endl;
    cout << popElement(s) << endl;
    cout << popElement(s) << endl;
}
