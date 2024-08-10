#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> createAdjList(vector<pair<int, int>> &edges, int v, int e)
{
    vector<list<int>> adjList(v);

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adjList[u].push_back(v);
    }
    return adjList;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<list<int>> adjList = createAdjList(edges, n, edges.size());
    vector<int> indegree(n);

    for (auto x : adjList)
    {
        for (auto y : x)
        {
            indegree[y]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        cnt++;

        for (int neighbour : adjList[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if (cnt == n)
        return false;
    return true;
}