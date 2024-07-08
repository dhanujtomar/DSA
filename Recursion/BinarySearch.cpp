#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int s, int e, int key)
{
    int mid = s + (e - s) / 2;

    if (s > e)
    {
        return -1;
    }

    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] < key)
        s = mid + 1;
    else
        e = mid - 1;

    return binarySearch(arr, s, e, key);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5, 6, 7, 8, 13, 14};

    cout << binarySearch(arr, 0, arr.size(), 13);
    return 0;
}