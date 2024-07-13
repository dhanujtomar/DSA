#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallerIndex(int *arr, int n)
{
    vector<int> nsi(n);
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        nsi[i] = s.top();
        s.push(i);
    }
    return nsi;
}

vector<int> prevSmallerIndex(int *arr, int n)
{
    vector<int> psi(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        psi[i] = s.top();
        s.push(i);
    }
    return psi;
}

int maxAreaInHistogram(int *arr, int n)
{
    vector<int> nsi = nextSmallerIndex(arr, n);
    vector<int> psi = prevSmallerIndex(arr, n);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nsi[i] == -1)
        {
            nsi[i] = n;
        }
        int width = nsi[i] - psi[i] - 1;
        int height = arr[i];
        int area = width * height;
        maxArea = std::max(area, maxArea);
    }

    return maxArea;
}

int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxAreaInHistogram(arr, n);

    return 0;
}