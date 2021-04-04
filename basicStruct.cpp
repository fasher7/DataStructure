#include <iostream>
using namespace std;

struct mango
{
    string color = "";
    int price = 0;
    float weight = 0.0;
    mango(string c, int p, float w)
    {
        color = c;
        price = p;
        weight = w;
    }
};

void setAttribute(mango& m, string c, int p, float w)
{
    m.color = c;
    m.price = p;
    m.weight = w;
}

void getAttribute(mango& m)
{
    cout << m.color << " " << m.price << " " << m.weight;
}

int main()
{
    string str = "";
    int price = 0;
    float weight = 0;

    cout << "Color of Mango: ";
    cin >> str;
    cout << "Price of Mango: ";
    cin >> price;
    cout << "Weight of Mango: ";
    cin >> weight;   
    mango m(str, price, weight);
    
    getAttribute(m);
    setAttribute(m, "red", 100, 50);
    cout << endl;
    getAttribute(m);

    return 0;
}
