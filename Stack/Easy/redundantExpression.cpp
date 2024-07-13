#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s = "((a+b))";
    stack<char> st;
    bool checkRedundant = false;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '+')
        {
            st.push(c);
        }
        else
        {
            if (c == ')')
            {
                if (st.top() == '(')
                {
                    checkRedundant = true;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    cout << checkRedundant;
    return 0;
}