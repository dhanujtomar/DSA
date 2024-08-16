#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> createAdjList(vector<vector<int>> &edges, int v)
{
    vector<list<int>> adjList(v);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, vector<list<int>> &adjList, vector<bool> &visited)
{

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adjList[node])
    {
        if (parent == nbr)
            continue;

        if (!visited[nbr])
        {
            dfs(nbr, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                result.push_back({node, nbr});
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    vector<list<int>> adjList = createAdjList(edges, v);

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;

    vector<bool> visited(v, false);

    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, parent, timer, disc, low, result, adjList, visited);
    }
    return result;
}