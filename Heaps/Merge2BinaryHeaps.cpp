#include <iostream>

using namespace std;

void mergeVectors(vector<int> &a, vector<int> &b, vector<int> &ans)
{
    for (int x : a)
        ans.push_back(x);

    for (int x : b)
        ans.push_back(x);
}

void toPosition(vector<int> &ans, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int curr = i;

    if (left < n && ans[left] > ans[curr])
        curr = left;
    if (right < n && ans[right] > ans[curr])
        curr = right;

    if (i != curr)
    {
        swap(ans[i], ans[curr]);
        toPosition(ans, n, curr);
    }
}

void heapify(vector<int> &ans, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        toPosition(ans, n, i);
    }
}

public:
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;

    mergeVectors(a, b, ans);

    heapify(ans, ans.size());

    return ans;
}

int main()
{

    return 0;
}