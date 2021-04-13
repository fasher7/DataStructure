#include <iostream>
using namespace std;

struct myStack
{
    int counter = 0;
    int size = 0;
    int *arr = nullptr;
    myStack(int s)
    {
        size = s;
        arr = new int[size];
    }
};

void enlarge(myStack *&st)
{
    st->size = st->size * 2;
    int *newArr = new int[st->size];
    for (int i = 0; i < st->size / 2; ++i)
    {
        newArr[i] = st->arr[i];
    }
    int *temp = st->arr;
    st->arr = newArr;
    delete[] temp;
}

void pushElm(myStack *&st, int x)
{
    if (st->counter == st->size)
    {
        enlarge(st);
    }
    st->arr[st->counter] = x;
    st->counter += 1;
}

int popElm(myStack *&st)
{
    st->counter -= 1;
    return st->arr[st->counter];
}

int main()
{
    myStack *st = new myStack(5); //choosing the size, 5 becomes 10
  
    pushElm(st, 10);
    pushElm(st, 20);
    pushElm(st, 30);
    pushElm(st, 40);
    pushElm(st, 50);
    pushElm(st, 60);
    pushElm(st, 70);
    pushElm(st, 80);
  
    cout << popElm(st) << endl;
    cout << popElm(st) << endl;
    cout << popElm(st) << endl;
    cout << popElm(st) << endl;
    cout << popElm(st) << endl;

    delete st;
    return 0;
}
