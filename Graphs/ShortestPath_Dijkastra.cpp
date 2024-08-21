#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

vector<list<pair<int, int>>> createAdjList(int n, int m, vector<vector<int>> &edges)
{

    vector<list<pair<int, int>>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    return adjList;
}

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{

    vector<list<pair<int, int>>> adjList = createAdjList(n, m, edges);

    vector<int> parent(n + 1, -1);

    vector<int> dist(n + 1, INT_MAX);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int S = 1;

    dist[S] = 0;

    pq.push({0, S});

    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();

        int node = front.second;
        int dis = front.first;

        for (auto nbr : adjList[node])
        {

            if (dist[nbr.first] > dis + nbr.second)
            {
                dist[nbr.first] = dis + nbr.second;

                pq.push({dist[nbr.first], nbr.first});
                parent[nbr.first] = node;
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }

    vector<int> path;

    int node = n;

    while (node != parent[node])
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    return path;
}