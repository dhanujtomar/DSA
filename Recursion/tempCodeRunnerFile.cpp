#include <iostream>
#include <vector>

using namespace std;

void subSequences(string &s, string output, int index, vector<string> &ans)
{
    if (index >= s.length())
    {
        if (output.length() > 0) // Empty element mat dalna
            ans.push_back(output);
        return;
    }

    subSequences(s, output, index + 1, ans);
    char element = s[index];
    output += element;
    subSequences(s, output, index + 1, ans);
}

void powerSet(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude
    powerSet(nums, output, index + 1, ans);

    // Include
    int element = nums[index];
    output.push_back(element);
    powerSet(nums, output, index + 1, ans);
}

int main()
{
    string s = "abc";

    vector<string> ans;
    string output = "";
    int index = 0;

    subSequences(s, output, index, ans);

    for (string x : ans)
    {
        cout << "{";
        for (char y : x)
        {
            cout << "{" << y << "}, ";
        }
        cout << "}" << endl;
    }

    return 0;
}

/*

int main()
{
    vector<int> set = {1, 2, 3};
    int n = set.size();

    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;

    powerSet(set, output, index, ans);

    cout << ans.size() << endl;

    for (vector<int> x : ans)
    {
        cout << "{";
        for (int y : x)
        {
            cout << "{" << y << "}, ";
        }
        cout << "}" << endl;
    }

    return 0;
}

*/