// https://www.geeksforgeeks.org/problems/word-break-part-23249/1

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void solve(unordered_map<string, bool> &mapping, string s, int i, int j, vector<string> &ans, string output)
    {

        if (s.length() == 0)
        {
            if (output.length() != 0)
            {
                output.pop_back();
                ans.push_back(output);
            }
            return;
        }

        if (j >= s.length())
        {
            return;
        }
        string word = s.substr(i, j + 1);
        if (mapping[word])
        {
            word += " ";
            solve(mapping, s.substr(j + 1), 0, 0, ans, output + word);
        }
        solve(mapping, s, i, j + 1, ans, output);
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        unordered_map<string, bool> mapping;

        for (int i = 0; i < n; i++)
            mapping[dict[i]] = true;

        vector<string> ans;
        string output;
        solve(mapping, s, 0, 0, ans, output);

        return ans;
    }
};