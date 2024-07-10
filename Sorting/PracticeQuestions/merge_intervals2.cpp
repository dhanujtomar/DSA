#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solve(vector<vector<int>> &nums)
{
    vector<int> arr;
    vector<int> temp;
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        arr.push_back(nums[i][0]);
        arr.push_back(nums[i][1]);
    }

    temp = arr;
    sort(arr.begin(), arr.end());
    for (int i = 1; i < temp.size(); i = i + 2)
    {
        if (arr[i] != temp[i])
        {
            arr[i] = -1;
        }
        else if (arr[i] == arr[i + 1])
        {
            arr[i] = -1;
        }
    }

    int i = 0, j = 1;
    int n = arr.size();

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int first;
        if (arr[i] != -1)
        {
            first = arr[i];
            i++;
        }
        while (arr[i] == -1)
        {
            i++;
        }
        ans.push_back({first, arr[i]});
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> nums = {{1, 4}, {4, 5}};

    vector<vector<int>> ans = solve(nums);

    for (vector<int> x : ans)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}