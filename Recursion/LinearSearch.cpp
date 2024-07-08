#include <iostream>

using namespace std;

int LinearSearchRec(int arr[], int n, int key)
{
    if (n == 0) // if n = 0  tk pahauch gye, toh element toh nahi hai
        return 1 + 1;
    if (arr[0] == key) // element milgya, return kardo index 0
        return 0;
    return 1 + LinearSearchRec(arr + 1, n - 1, key); // return kardo 1+0 -> 1+1 -> 1+2 -> 1+3 ......
}

bool LinearSearch_present(int arr[], int n, int key)
{
    if (n == 0)
        return false;
    if (arr[0] == key)
        return true;
    return LinearSearch_present(arr + 1, n - 1, key);
}

int main()
{
    int arr[] = {3, 4, 6, 2, 7, 2, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << LinearSearch_present(arr, n, 3) << endl;
}