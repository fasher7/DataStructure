#include <iostream>
using namespace std;

struct myQueue
{
    int head = 0;
    int tail = 0;
    int *elements = new int[5];
};

void enqueueElement(myQueue *&q, int x)
{
    q->elements[q->tail] = x;
    q->tail += 1;
}

int dequeueElement(myQueue *&q)
{
    int x = q->elements[q->head];
    q->head += 1;
    return x;
}

int main()
{
    myQueue *q = new myQueue;
    enqueueElement(q, 10);
    enqueueElement(q, 20);
    enqueueElement(q, 30);
    enqueueElement(q, 40);
    enqueueElement(q, 50);

    cout << dequeueElement(q) << endl;
    cout << dequeueElement(q) << endl;
    cout << dequeueElement(q) << endl;
    cout << dequeueElement(q) << endl;

    return 0;
}
