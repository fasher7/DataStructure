#include <iostream>
using namespace std;

struct flower
{
    int price = 10;
    flower* nextFlower = nullptr;
};

void printList(flower* f)
{
    while (f != nullptr)
    {   
        cout << f->price << endl;
        f = f -> nextFlower;
    }   
}

int main()
{
    flower* rose = new flower();
    rose -> price = 10;

    flower* tulip = new flower();
    tulip -> price = 20;

    flower* sunflower = new flower();
    sunflower -> price = 30;

    flower* lily = new flower();
    lily -> price = 40;

    rose -> nextFlower = tulip;
    tulip -> nextFlower = sunflower;
    sunflower -> nextFlower = lily;

    printList (rose);

    return 0;
}
