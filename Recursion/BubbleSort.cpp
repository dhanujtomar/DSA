#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &arr, int i, int n)
{
    if (i >= n - 1)
    {
        return;
    }
    if (arr[i] > arr[i + 1])
        swap(arr[i], arr[i + 1]);

    BubbleSort(arr, i + 1, n);
}

void babbarSort(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    babbarSort(arr, n - 1);
}

int main()
{
    vector<int> arr = {2, 3, 1, 6, 4, 7, 5};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // BubbleSort(arr, 0, n - i);
    }
    babbarSort(arr, n);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}