#include <iostream>
using namespace std;

int main()
{
    int row = 4;
    int a = 1;
    int **firstp = new int *[row];

    for (int i = 0; i < row; i++)
    {
        firstp[i] = new int[i + 1];
    }

    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x <= y; x++)
        {
            firstp[y][x] = a;
            a++;
        }
    }

    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x <= y; x++)
        {
            cout << firstp[y][x] << " ";
        }
        cout << endl;
    }

    for (int b = 0; b < row; ++b)
    {
        delete [] firstp[b];
    }
    delete [] firstp;
    firstp = nullptr;

    return 0;
}
