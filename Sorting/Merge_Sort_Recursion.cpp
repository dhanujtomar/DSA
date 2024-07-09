#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int s, int mid, int e)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    k = s;

    int firstIndex = 0;
    int secondIndex = 0;

    while (firstIndex < len1 && secondIndex < len2)
    {
        if (first[firstIndex] < second[secondIndex])
            arr[k++] = first[firstIndex++];
        else
            arr[k++] = second[secondIndex++];
    }

    while (firstIndex < len1)
    {
        arr[k++] = first[firstIndex++];
    }

    while (secondIndex < len1)
    {
        arr[k++] = second[secondIndex++];
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s >= e)
    {
        return;
    }
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}