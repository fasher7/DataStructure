#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(12); //enqueue
    q.push(13);
    q.push(14);
    q.push(15);

    while (!q.empty())
    {
        cout << q.front() << endl; //first value
        q.pop(); //dequeue & delete
    }
}
