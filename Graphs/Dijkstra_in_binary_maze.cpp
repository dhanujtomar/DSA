#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int row;
    int col;
    int wt;

    Node(int r, int c, int w) : row(r), col(c), wt(w) {}
};

bool cond(int nrow, int ncol, vector<vector<int>> &grid, vector<vector<int>> &dist, int row, int col)
{
    int n = grid.size();
    int m = grid[0].size();

    return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) &&
           (grid[nrow][ncol] == 1) &&
           (dist[nrow][ncol] > dist[row][col] + 1);
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{

    if (destination.first == source.first && destination.second == source.second)
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};

    // priority_queue<Node*, vector<Node*>, cmp> pq;
    queue<Node *> pq;

    Node *st = new Node(source.first, source.second, 0);

    pq.push(st);

    dist[source.first][source.second] = 0;

    while (!pq.empty())
    {
        // Node* front = pq.top();
        Node *front = pq.front();
        pq.pop();

        int row = front->row;
        int col = front->col;
        int wt = front->wt;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (cond(nrow, ncol, grid, dist, row, col))
            {
                dist[nrow][ncol] = dist[row][col] + 1;

                Node *temp = new Node(nrow, ncol, dist[nrow][ncol]);
                pq.push(temp);

                if (destination.first == nrow && destination.second == ncol)
                {
                    return dist[nrow][ncol];
                }
            }
        }
    }

    return -1;
}

vector<vector<int>> createMatrix_1()
{

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 1}};

    return grid;
}

int main()
{
    vector<vector<int>> grid = createMatrix_1();

    int n = grid.size();
    int m = grid[0].size();

    cout << shortestPath(grid, {0, 1}, {2, 2}) << endl;

    return 0;
}