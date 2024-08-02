#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {3, 3, 3, 3, 3};
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