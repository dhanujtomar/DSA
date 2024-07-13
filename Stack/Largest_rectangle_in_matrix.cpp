#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallerIndex(vector<int> arr, int n)
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

vector<int> prevSmallerIndex(vector<int> arr, int n)
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

int maxAreaInHistogram(vector<int> arr, int n)
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
    vector<vector<int>> M = {
        // {1, 1, 1, 1},
        // {1, 1, 1, 1},
        // {1, 1, 1, 1},
        // {1, 1, 0, 0}
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    int n = M.size();
    int m = M[0].size();

    int area = maxAreaInHistogram(M[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];
        }
        area = std::max(area, maxAreaInHistogram(M[i], m));
    }

    cout << area;

    return 0;
}