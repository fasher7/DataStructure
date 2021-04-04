#include <iostream>
using namespace std;

void deleteMemory(int** a, int c , int* b) 
{
    for (int i = 0; i < c; ++i)
    {
        delete[] a[i];
    }
    delete[] b;
}

void printMarks(int** arr, int numSemester, int* subjEachSem) 
{
    cout << "Marks each semester: " << endl;
    for (int i = 0; i < numSemester; ++i) 
    {
        for (int j = 0; j < subjEachSem[i]; ++j) 
        {
        cout << arr[i][j] << " ";
        }
    cout << endl;
    }
    deleteMemory(arr, numSemester, subjEachSem);
}

void getMarks(int** arr, int numSemester) 
{
    int* subjEachSem = new int[numSemester];
    for (int i = 0; i < numSemester; ++i) 
    {
        int N = 0;
        cout << "Num of subjects in sem " << i+1 << ": ";
        cin >> N;
        arr[i] = new int[N];
        subjEachSem[i] = N;
        for (int j = 0; j < N; ++j)
        {
            cout << "Course " << j+1 << ": ";
            cin >> arr[i][j];
        }
    }
    printMarks(arr, numSemester, subjEachSem);
}

int main() 
{
    // 100 98 - 1st semester
    // 90 89 100 88 - 2nd semester
    // 100 99 89 - 3rd semester
    int numSemester = 0;
    cout << "Enter num of semesters: ";
    cin >> numSemester;
    int** arr = new int* [numSemester];
    getMarks(arr, numSemester);
    return 0;
}
