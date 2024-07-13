#include <iostream>
#include <stack>

using namespace std;

void compare(stack<int> &s, int n)
{
    if (s.empty() || s.top() >= n)
    {
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    compare(s, n);
    s.push(num);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;

    int num = s.top();
    s.pop();
    sortStack(s);
    compare(s, num);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}