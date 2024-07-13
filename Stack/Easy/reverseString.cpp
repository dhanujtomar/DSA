#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s = "abcde";

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans;

    return 0;
}