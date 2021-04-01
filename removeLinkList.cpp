#include <iostream>
using namespace std;

struct flower
{
    int price = 0;
    flower* nextFlower = nullptr;
};

void removeValue(flower* rose)  // works sane with *& as well
{
    //to delete sunflower from the link list
    flower* f = rose;
    while (f -> nextFlower != nullptr)
    {
        if (f -> nextFlower -> price == 30)  //tulip's next is sunflower
        {
            flower *junk = f -> nextFlower; //took sunflower's address
            f -> nextFlower = f -> nextFlower -> nextFlower; //avoided sunflower; f == lily
            delete junk;
        }
        else
        {
            f = f -> nextFlower;
        }
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

    cout << "Rose: " << rose << endl;
    cout << "Tulip: " << tulip << endl;
    cout << "Sunflower: " << sunflower << endl;
    cout << "Lily: " << lily << endl;
    
    removeValue(rose);
    
    cout << "Rose: " << rose -> price << endl;
    cout << "Tulip: " << tulip -> price << endl;
    cout << "Sunflower: " << sunflower -> price << endl; //no value so garbage
    cout << "Lily: " << lily -> price << endl;
    
    cout << rose -> nextFlower << endl;
    cout << rose -> nextFlower -> nextFlower << endl; 
    // ^ printed lily's address instead of sunflower as it got deleted
    // The variable sunflower didn't get deleted but from the list it got deleted
    
    return 0;
}
