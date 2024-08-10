#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

unordered_map<int, list<int>> createAdjList(vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    return adjList;
}

bool isCycle_DFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVis, int node)
{
    visited[node] = true;
    dfsVis[node] = true;

    for (int neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool ans = isCycle_DFS(adjList, visited, dfsVis, neighbour);
            if (ans)
                return true;
        }
        else if (dfsVis[neighbour])
            return true;
    }

    dfsVis[node] = false;

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList = createAdjList(edges);
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVis;

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycle_DFS(adjList, visited, dfsVis, i);
            if (ans)
                return 1;
        }
    }

    return 0;
}