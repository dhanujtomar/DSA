#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(string &s, int index, vector<string> &ans)
{
    if (index >= s.length())
    {

        ans.push_back(s);

        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        solve(s, index + 1, ans);
        swap(s[index], s[i]);
    }
}

int main()
{
    string s = "abc";
    vector<string> ans;
    string out;
    int index = 0;

    solve(s, index, ans);

    for (string x : ans)
    {
        for (char c : x)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}