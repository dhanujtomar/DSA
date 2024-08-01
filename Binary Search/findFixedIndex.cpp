#include <iostream>
#include <vector>

using namespace std;

int findFixed(vector<int> &nums, int n)
{
    int s = 0, e = n - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == mid)
        {
            return mid;
        }
        else if (nums[mid] > mid)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    vector<int> nums = {-10, -1, 0, 3, 10, 11, 30, 50, 100};

    int n = nums.size();

    cout << findFixed(nums, n);
}