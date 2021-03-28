#include <iostream>
#include <sstream>
using namespace std;

string getString()
{
    string str = " ";
    getline (cin, str);
    return str;
}

float toFloat (string str)
{
    float i = 0;
    stringstream ss;
    ss << str;
    if (ss >> i)
    {
        return i;
    }
    else
    {
        cout << "Error!" << endl;
        return 0;
    }
}

float getFloat ()
{
    string str = getString();
    float f = toFloat(str);
    return f;
}

int main()
{
    float sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        string str = ""; float price = 0.0;
        cout << "Name: ";
        str = getString();
        cout << "Price ";
        price = getFloat();
        sum = sum + price;
    }
    cout << sum << endl;
    return 0;
}
