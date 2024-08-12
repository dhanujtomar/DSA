#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits.h>
#include <queue>

using namespace std;

unordered_map<int, list<pair<int, int>>> createAdjList(int m, vector<pair<pair<int, int>, int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adjList;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    return adjList;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList = createAdjList(m, g);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;
    parent[1] = -1;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto nodePair = pq.top();
        pq.pop();

        int node = nodePair.second;
        if (mst[node])
            continue;

        mst[node] = true;

        for (auto neighbourNode : adjList[node])
        {
            int v = neighbourNode.first;
            int w = neighbourNode.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = node;
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
        result.push_back({{parent[i], i}, key[i]});

    return result;
}
