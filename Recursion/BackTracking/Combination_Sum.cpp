#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void solve(vector<int> &A, int B, int index, int sum, vector<vector<int>> &ans, vector<int> output)
    {
        if (sum > B)
            return;

        if (sum == B)
        {
            ans.push_back(output);
        }

        for (int i = index; i < A.size(); i++)
        {
            sum += A[i];
            output.push_back(A[i]);

            solve(A, B, i, sum, ans, output);

            sum -= A[i];
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        set<int> s;

        for (int x : A)
        {
            s.insert(x);
        }

        A.clear();

        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            A.push_back(*itr);
        }

        int sum = 0;

        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(A, B, index, sum, ans, output);

        return ans;
    }
};