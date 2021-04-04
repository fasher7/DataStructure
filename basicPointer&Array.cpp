include <iostream>
using namespace std;

int main()
{
    const int N = 3;
    int arr[N] = {1,2,3};
    cout << (arr+0) << endl;
    cout << *(arr+0) << endl;
    cout << (arr+1) << endl;
    cout << *(arr+1) << endl; 
    cout << (arr+2) << endl;
    cout << *(arr+2) << endl;
    int *p = arr;
    cout << *(p++) << endl; 
    cout << *(p++) << endl;
    cout << *(p) << endl;    
}
