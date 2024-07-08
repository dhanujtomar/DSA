#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3, int n, int m)
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6};
    int n = arr1.size();
    int m = arr2.size();

    vector<int> arr3(n + m);

    merge(arr1, arr2, arr3, n, m);

    for (int x : arr3)
    {
        cout << x << " ";
    }

    return 0;
}