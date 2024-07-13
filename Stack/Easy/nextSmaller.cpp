#include <iostream>
#include <stack>

using namespace std;

void nextSmaller(int *arr, int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            arr[i] = -1;
        }
        else
        {
            if (s.top() <= arr[i])
            {
                arr[i] = s.top();
            }
            else
            {
                s.pop();
                s.push(arr[i]);
                arr[i] = -1;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextSmaller(arr, n);

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}