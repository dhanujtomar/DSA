#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>&arr, int e, int num)
{
    int s = 0;
    // int mid = (s + e) / 2;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == num)
        {
            return mid;
        }
        if (num > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        // mid = (s + e) / 2;      // for larger values of s and e the sum of s and e will be more than the range of int
        mid = s + (e - s) / 2;
    }

    return -1;
}

int lowerBound(vector<int>&arr, int e, int key)
{
    int s = 0;
    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            e = mid - 1;
        }
        if (key > arr[mid])
        {
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

int upperBound(vector<int>&arr, int e, int key)
{
    int s = 0;
    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            s = mid + 1;
        }
        if (key > arr[mid])
        {
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

int main()
{
    // int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 19};
    vector<int> arr = {5,7,7,8,8,10};
    int num = 19;

    cout << binarySearch(arr, e - 1, num) << endl;

    cout << lowerBound(arr, e - 1, num) << endl;

    cout << upperBound(arr, e - 1, num) << endl;
    return 0;
}