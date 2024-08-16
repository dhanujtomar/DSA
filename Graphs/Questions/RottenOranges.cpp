#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    class Node
    {
    public:
        int row;
        int col;
        int timer;

        Node(int r, int c, int t) : row(r), col(c), timer(t) {}
    };

public:
    bool cond(int nrow, int ncol, vector<vector<int>> &grid,
              vector<vector<bool>> &visited)
    {

        int n = grid.size();
        int m = grid[0].size();

        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) &&
               (grid[nrow][ncol] == 1 && !visited[nrow][ncol]);
    }

    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,
            vector<int> &delRow, vector<int> &delCol)
    {

        queue<Node *> q;

        int countFresh = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    Node *temp = new Node(i, j, 0);
                    q.push(temp);
                }

                if (grid[i][j] == 1)
                    countFresh++;
            }
        }

        int maxi = 0;

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            int row = front->row;
            int col = front->col;
            int timer = front->timer;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (cond(nrow, ncol, grid, visited))
                {
                    visited[nrow][ncol] = true;
                    countFresh--;

                    Node *temp = new Node(nrow, ncol, timer + 1);
                    q.push(temp);
                    maxi = max(maxi, timer + 1);
                }
            }
        }
        if (countFresh == 0)
            return maxi;
        return -1;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> delRow = {0, 0, -1, +1};
        vector<int> delCol = {-1, +1, 0, 0};

        return bfs(grid, visited, delRow, delCol);
    }
};