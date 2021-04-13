#include <iostream>
using namespace std;

struct myQueue
{
    int head = 0;
    int tail = 0;
    int size = 0;
    char *arr = nullptr;
    myQueue(int s)
    {
        size = s;
        arr = new char[size];
    }
};

void enlarge(myQueue *&q)
{
    q->size = q->size * 2;
    char *newArr = new char[q->size];
    for (int i = 0; i < q->size / 2; ++i)
    {
        newArr[i] = q->arr[(q->head + i) % (q->size / 2)];
    }
    char *temp = q->arr;
    q->arr = newArr;
    delete[] temp;
    q->head = 0;
    q->tail = (q->size) / 2;
}

void enq(myQueue *&q, char x)
{
    if (q->tail - q->head == q->size)
    {
        cout << "Enlarge function called" << endl;
        enlarge(q);
    }
    q->arr[q->tail % q->size] = x;
    q->tail += 1;
}

char deq(myQueue *&q)
{
    char x = q->arr[q->head % q->size];
    q->head += 1;
    return x;
}

int main()
{
    myQueue *q = new myQueue(5);
    enq(q, 'A');
    enq(q, 'B');
    enq(q, 'C');
    enq(q, 'D');
    enq(q, 'E');

    cout << deq(q) << endl;
    cout << deq(q) << endl;

    enq(q, 'F');
    enq(q, 'G');

    cout << endl;
    enq(q, 'H');
    cout << endl;

    cout << "---" << endl;
    cout << deq(q) << endl;
    cout << deq(q) << endl;
    cout << deq(q) << endl;
    cout << deq(q) << endl;
    cout << deq(q) << endl;

    return 0;
}
