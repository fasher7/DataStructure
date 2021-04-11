#include <iostream>
using namespace std;

struct myStack
{
    int counter = 0;
    int size = 0;
    int *arr;
    myStack(int s)
    {
        size = s;
        arr = new int[size];
    }
};

void swapAddress(int *&a, int *&b)
{
    int *temp = a;
    a = b;
    b = temp;
}
void enlarge(myStack *&st)
{
    st->size = st->size * 2;
    int *newArr = new int[st->size];

    for (int i = 0; i < st->size / 2; ++i)
    {
        newArr[i] = st->arr[i];
    }
    swapAddress(st->arr, newArr);
    delete newArr;
}

bool isEmpty(myStack *&st)
{
    return (st->counter == 0);
}

void push(myStack *&st, int val)
{

    if (st->counter == st->size)
    {
        enlarge(st);
    }

    st->arr[st->counter] = val;
    st->counter = st->counter + 1;
}

int pop(myStack *&st)
{
    if (!isEmpty(st))
    {
        st->counter = st->counter - 1;
        return st->arr[st->counter];
    }
    else
    {
        return -10000;
    }
}

int main()
{
    myStack *st = new myStack(5);
    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);
    push(st, 50);
    push(st, 60);
    push(st, 70);
    push(st, 70);
    push(st, 70);
    push(st, 70);
    push(st, 70);
    cout << pop(st) << endl;
    cout << pop(st) << endl;

    cout << pop(st) << endl;
    cout << pop(st) << endl;

    cout << pop(st) << endl;

    cout << pop(st) << endl;
    cout << pop(st) << endl;
    cout << pop(st) << endl;
    cout << pop(st) << endl;
}
