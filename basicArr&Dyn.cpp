#include <iostream>
using namespace std;

int main()
{
    int* odd = new int[2]{1,3};
    int* even = new int[4]{2,4,6,8};
    int* natural = new int[3]{1,2,3};

    int indArr[3] = {2,4,3};

    int** arr = new int*[3]{odd, even, natural};
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < indArr[i]; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
