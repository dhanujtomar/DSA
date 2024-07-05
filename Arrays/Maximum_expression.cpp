#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    string s;
    cin >> s;
    priority_queue<char> ops; // lowest operator gets first position ie: +

    // priority queue with greatest elements positioned first
    priority_queue<char, vector<char>, greater<char>> nums; // insertion o(log(n))

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '+' || c == '-')
        {
            ops.push(c);
        }
        else
        {
            nums.push(c);
        }
    }
    vector<char> c;

    // Enter elements to the back of "vector c"
    // first the lowest number gets added then the lowest operator
    // loop repeats itself until the operator queue is empty
    while (ops.size())
    {
        c.push_back(nums.top());
        c.push_back(ops.top());
        ops.pop();
        nums.pop();
    }

    // enter the remaining numbers in the "vector c"
    while (nums.size())
    {
        c.push_back(nums.top());
        nums.pop();
    }

    // print answer
    for (int i = n - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    cout << endl;
}

int main()
{
    // your code goes here
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        solve(n);
    }
}
