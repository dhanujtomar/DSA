#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        if (i < n - 1 && arr[i + 1][0] >= arr[i][0] && arr[i + 1][0] <= arr[i][1])
        {
            ans.push_back({arr[i][0], arr[i + 1][1]});
            i++;
        }
        else if (i < n - 1 && arr[i + 1][0] <= arr[i][0] && arr[i + 1][1] <= arr[i][1])
        {
            ans.push_back({arr[i + 1][0], arr[i + 1][1]});
            i++;
        }
        else
        {
            ans.push_back({arr[i][0], arr[i][1]});
        }
    }
    return ans;
}

int main()
{
    // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    // vector<vector<int>> intervals = {{1, 4}, {1, 4}};
    vector<vector<int>> intervals = {{1, 4}, {0, 4}};

    vector<vector<int>> ans = merge(intervals);

    cout << ans.size() << endl;

    for (vector<int> x : ans)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}