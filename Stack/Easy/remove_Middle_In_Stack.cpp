#include <iostream>
#include <stack>

using namespace std;

void removeMiddle(stack<int> &s, int index, int size)
{
    if (index >= size / 2)
    {
        s.pop();
        return;
    }
    int element = s.top();
    s.pop();
    removeMiddle(s, index + 1, size);
    s.push(element);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    removeMiddle(st, 0, st.size());

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}