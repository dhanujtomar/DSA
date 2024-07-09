#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int> &arr, int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s; // s return krdo ya e return krdo ek hi baat hai // loop e=s pe hi khatam hoga
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();

    cout << pivot(arr, n);

    return 0;
}