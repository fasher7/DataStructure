#include <iostream>
using namespace std;

struct flower
{
    int price = 0;
    flower* nextFlower = nullptr;
};

void printList(flower* f)
{
    while(f != nullptr)
    {
        cout << f->price << endl;
        f = f-> nextFlower;
    }
    cout << endl;
}

void addNode(flower*& f, int value)
{
    if (f == nullptr)
    {
        f = new flower();
        f -> price = value;
    }
    else
    {
        flower* g = f;
        while(g -> nextFlower != nullptr)
        {
          g = g -> nextFlower;
        }
        flower* p = new flower();
        p -> price = value;
        g -> nextFlower = p;
    }
}

int main()
{
    flower* p = nullptr;

    addNode(p, 20);
    addNode(p, 30);
    addNode(p, 40);
    addNode(p, 50);    
    printList(p);

    return 0;
}
