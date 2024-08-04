#include <iostream>

using namespace std;

void heapifyInt(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyInt(arr, n, largest);
    }
}

void heapify(int *arr, int n)
{

    // leaves start at n/2+1

    // all root nodes will end at n/2 string from i=1

    for (int i = n / 2 - 1; i > 0; i--)
        heapifyInt(arr, n, i);
}

int main()
{
    int arr[] = {-1, 50, 55, 53, 52, 54};
    // int arr[] = {-1, 54, 53, 55, 52, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    heapify(arr, n);

    for (int x : arr)
    {
        if (x == -1)
            continue;
        cout << x << " ";
    }
    return 0;
}