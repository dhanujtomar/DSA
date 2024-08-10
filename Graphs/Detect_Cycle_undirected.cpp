#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

vector<list<int>> createAdjList(vector<vector<int>> &edges, int m, int n)
{
    vector<list<int>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return adjList;
}

bool checkCycleBFS(unordered_map<int, bool> &visited, vector<list<int>> &adjList, int src)
{
    queue<int> q;
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;

    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode])
        {
            if (visited[neighbour] == true && neighbour != parent[frontNode])
                return true;
            
            else if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<list<int>> adjList = createAdjList(edges, m, n);
    unordered_map<int, bool> visited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = checkCycleBFS(visited, adjList, i);
            if (ans)
                return "Yes";
        }
    }

    return "No";
}
