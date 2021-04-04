include <iostream>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int *dym = new int[N];   //space allocation
    for (int i = 0; i < N; ++i)
    {
        cin >> dym[i];
    }    
    for (int i = 0; i < N; ++i)
    {
        cout << dym[i] << " ";
    }
    delete[] dym;
}
