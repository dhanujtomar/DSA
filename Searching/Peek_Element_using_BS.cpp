#include <iostream>

using namespace std;

int getPivotElement(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] > arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
}

int main()
{
    int arr[] = {0, 7, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    getPivotElement(arr, n);
}