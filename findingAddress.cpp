#include <iostream>
using namespace std;

void multarr(double arr[], int size)
{
    cout << endl;
    cout << "Using Array to find its Address" << endl;
    cout << arr << endl;
    cout << *arr << endl;
    cout << arr + 1 << endl;
    cout << *(arr + 1) << endl;
    // we can't find the total bytes of this array using sizeof(arr)
    // as the array is passed into a function
    cout << endl;
}

int main()
{
    double arr[5] = {-8, 2.5, 7, -23, 5};
    double *p;
    p = arr;
    cout << "Using Pointers to find Array Address" << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << p + 1 << endl;
    cout << *(p + 1) << endl;
    cout << "Address of the Pointer: " << &p << endl;
    // we can find the total bytes of this array using sizeof(arr)
    multarr(arr, 5);

    return 0;
}
