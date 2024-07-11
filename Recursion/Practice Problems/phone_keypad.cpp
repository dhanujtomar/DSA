#include <iostream>
#include <vector>

using namespace std;

void solve(string &digits, int index, vector<string> &mapping, string output, vector<string> &ans)
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    int digit = digits[index] - '0';
    string letters = mapping[digit];

    for (int i = 0; i < letters.length(); i++)
    {
        output.push_back(letters[i]);
        solve(digits, index + 1, mapping, output, ans);
        output.pop_back();
    }
}

int main()
{
    string digits = "234";
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output;
    int index = 0;

    solve(digits, index, mapping, output, ans);

    for (string x : ans)
    {
        cout << x << endl;
    }

    return 0;
}