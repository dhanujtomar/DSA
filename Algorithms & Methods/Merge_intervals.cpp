#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cond(vector<int> &pairs, vector<int> nums)
{
    return (pairs[0] <= nums[0] && pairs[1] >= nums[0]);
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    std::sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    vector<int> pairs(2);
    pairs[0] = intervals[0][0];
    pairs[1] = intervals[0][1];

    int index = 1;

    while (index < n)
    {
        if (cond(pairs, intervals[index]))
        {
            pairs[1] = max(intervals[index][1], pairs[1]);
        }
        else
        {
            ans.push_back(pairs);
            pairs[0] = intervals[index][0];
            pairs[1] = intervals[index][1];
        }
        index++;
    }
    ans.push_back(pairs);

    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> ans = merge(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "]";
    }

    return 0;
}