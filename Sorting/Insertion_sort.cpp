#include <iostream>

using namespace std;

int main()
{
    int arr[] = {10, 1, 7, 4, 8, 2, 11};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int element = arr[i];
        int j = i - 1;
        while (arr[j] > element && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
}