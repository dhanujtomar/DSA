#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (q.size() < k)
                q.push(sum);
            else
            {
                if (q.top() < sum)
                {
                    q.pop();
                    q.push(sum);
                }
            }
        }
    }
    return q.top();
}