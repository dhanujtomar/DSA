#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{

    bool cond(int nrow, int ncol, vector<vector<int>> &image,
              vector<vector<bool>> &visited, int key)
    {

        int n = image.size();
        int m = image[0].size();

        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) &&
               (image[nrow][ncol] == key && !visited[nrow][ncol]);
    }

    void bfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int sr, int sc, vector<vector<int>> &ans, int newColor)
    {
        queue<pair<int, int>> q;

        q.push({sr, sc});

        visited[sr][sc] = true;

        int key = image[sr][sc];

        ans[sr][sc] = newColor;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int row = front.first;
            int col = front.second;

            for (int delRow = -1; delRow <= 1; delRow++)
            {

                int nrow = row + delRow;
                int ncol = col;

                if (cond(nrow, ncol, image, visited, key))
                {
                    visited[nrow][ncol] = true;
                    ans[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }

            for (int delCol = -1; delCol <= 1; delCol++)
            {

                int nrow = row;
                int ncol = col + delCol;

                if (cond(nrow, ncol, image, visited, key))
                {
                    visited[nrow][ncol] = true;
                    ans[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<vector<int>> ans = image;

        bfs(image, visited, sr, sc, ans, newColor);

        return ans;
    }
};