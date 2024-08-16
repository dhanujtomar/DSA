#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool cond(int nrow, int ncol, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {

        int n = grid.size();
        int m = grid[0].size();

        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) && (!visited[nrow][ncol]);
    }

    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<vector<int>> &dist, vector<int> &delRow, vector<int> &delCol)
    {

        vector<vector<int>> ans = grid;

        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                if (grid[i][j] == 1)
                {

                    q.push({i, j});

                    dist[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int row = front.first;
            int col = front.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (cond(nrow, ncol, ans, visited))
                {
                    dist[nrow][ncol] = dist[row][col] + 1;

                    visited[nrow][ncol] = true;

                    q.push({nrow, ncol});
                }
            }
        }
    }

    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, -1));

        vector<int> delRow = {0, 0, -1, +1};
        vector<int> delCol = {-1, +1, 0, 0};

        bfs(grid, visited, dist, delRow, delCol);

        return dist;
    }
};