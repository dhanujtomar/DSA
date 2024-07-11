#include <iostream>
#include <vector>

using namespace std;

void solve(string &s, int index, string output, vector<string> &ans)
{
    if (index >= s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);

        solve(s, index + 1, output, ans);
        swap(s[i], s[index]);
    }
}

int main()
{
    string s = "abc";
    vector<string> ans;
    string output;
    int index = 0;

    solve(s, index, output, ans);

    for (string x : ans)
    {
        cout << x << endl;
    }

    return 0;
}