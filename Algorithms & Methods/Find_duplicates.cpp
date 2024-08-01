#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1, 7, 8};
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = nums[i] ^ ans;
    }

    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }

    cout << ans;

    return 0;
}