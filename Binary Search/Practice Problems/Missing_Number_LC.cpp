#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    std::sort(nums.begin(), nums.end());

    if (nums[e] == e)
    {
        return e + 1;
    }

    while (s <= e)
    {
        if (mid == nums[mid])
        {
            s = mid + 1;
        }
        else if (mid < nums[mid])
        {
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {
        {3, 0, 1},
        {0, 1},
        {9, 6, 4, 2, 3, 5, 7, 0, 1}};

    int tc = v.size();

    for (int i = 0; i < tc; i++)
    {
        cout << missingNumber(v.at(i)) << endl;
    }
}