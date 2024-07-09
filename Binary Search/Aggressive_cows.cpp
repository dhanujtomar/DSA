#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, int n)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
                return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int mini = stalls[0];
    int maxi = stalls[n - 1];

    int s = 0;
    int e = maxi - mini;
    int mid = s + (e - s) / 2;

    int ans;

    while (s <= e)
    {
        if (isPossible(stalls, k, mid, n))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}