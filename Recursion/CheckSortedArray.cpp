#include <iostream>
using namespace std;

bool checkSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return checkSorted(arr + 1, n - 1);
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5, 5, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << checkSorted(arr, n) << endl;

    return 0;
}