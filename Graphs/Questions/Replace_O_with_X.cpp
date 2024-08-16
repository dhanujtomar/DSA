#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool cond(int nrow, int ncol, vector<vector<bool>> &visited, vector<vector<char>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) && (!visited[nrow][ncol] && mat[nrow][ncol] == 'O');
    }

    void dfs(vector<vector<bool>> &visited, vector<vector<char>> &mat, int row, int col, vector<int> &delRow, vector<int> &delCol)
    {

        visited[row][col] = true;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (cond(nrow, ncol, visited, mat))
            {
                dfs(visited, mat, nrow, ncol, delRow, delCol);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> delRow = {0, 0, -1, 1};
        vector<int> delCol = {-1, 1, 0, 0};

        // first and last cols
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && mat[i][0] == 'O')
                dfs(visited, mat, i, 0, delRow, delCol);

            if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
                dfs(visited, mat, i, m - 1, delRow, delCol);
        }

        // first and last rows
        for (int i = 0; i < m; i++)
        {
            if (!visited[0][i] && mat[0][i] == 'O')
                dfs(visited, mat, 0, i, delRow, delCol);

            if (!visited[n - 1][i] && mat[n - 1][i] == 'O')
                dfs(visited, mat, n - 1, i, delRow, delCol);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (!visited[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};