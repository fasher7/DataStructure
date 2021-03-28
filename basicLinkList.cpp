#include <iostream>
using namespace std;

struct flower
{
    int price = 0;
    flower* next = nullptr;
};

int main()
{
    flower* rose = new flower;
    rose -> price = 14;

    flower* tulip = new flower;
    tulip -> price = 24;

    flower* sunflower = new flower;
    sunflower -> price = 48;

    rose -> next = tulip;
    tulip -> next = sunflower;
    sunflower -> next = rose;

    int i = 6;
    while (i--)
    {
        cout << rose -> price << endl;
        cout << rose << endl;
        rose = rose -> next;
    }

    return 0;
}
