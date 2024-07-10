#include <iostream>
#include <vector>

using namespace std;

void solve(string &digits, vector<string> &mapping, int index, string output, vector<string> &ans)
{
    if (index >= digits.size())
    {
        ans.push_back(output);
        return;
    }
    int num = digits[index] - '0';
    string value = mapping[num];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, mapping, index + 1, output, ans);
        output.pop_back();
    }
}

int main()
{
    string digits = "23";
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output;
    int index = 0;
    solve(digits, mapping, index, output, ans);

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