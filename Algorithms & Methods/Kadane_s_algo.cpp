#include <iostream>
#include <vector>

using namespace std;

long long maxSubarraySum(vector<int> &arr)
{
    long long sum = 0;
    long long maxi = arr[0];

    for (long i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums = {1, 2, 3, -2, 5};

    cout << maxSubarraySum(nums); // Ans -> 9 for {1, 2, 3, -2, 5} array

    return 0;
}