#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(12);
    l.push_back(13);
    l.push_back(14);

    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << (*it) << endl;
    }

    return 0;
}
