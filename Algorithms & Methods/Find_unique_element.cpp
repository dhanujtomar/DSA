#include <iostream>
#include <vector>

using namespace std;

// O(n) -  Done using the XOR operator

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4, 4, 2};

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }

    cout << ans << endl;
    return 0;
}