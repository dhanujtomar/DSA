#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int s = 0, e = n;
    int mid = s + (e - s) / 2;

    int ans = 0;

    while (s <= e)
    {
        if (!isBadVersion(mid))
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}