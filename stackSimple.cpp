#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(5);
    st.push(6);
    st.push(7);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
