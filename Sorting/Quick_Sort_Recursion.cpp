#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int> arr, int s, int e)
{
    int pivotElement = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++) // count number of elements greater than pivot element
    {
        if (arr[i] <= pivotElement)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]); // set pivot element to its right(correct) index

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement) // increment i till pivot element is smaller than arr[i]
            i++;
        while (arr[j] > pivotElement) // decrement j till pivot element is greater than arr[j]
            j--;

        if (i < pivotIndex && j > pivotIndex) // if out of both while loops check the condition, if true -> swap
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void dhanujPivot(vector<int> arr, int s, int e)
{
}

void qucikSort(vector<int> arr, int s, int e)
{
    if (s >= e)
        return;

    int pivotIndex = pivot(arr, s, e);

    // first half
    qucikSort(arr, s, pivotIndex - 1);

    // second half
    qucikSort(arr, pivotIndex + 1, e);
}

int main()
{
    vector<int> arr = {3, 5, 1, 6, 4};

    int n = arr.size();

    qucikSort(arr, 0, n - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}