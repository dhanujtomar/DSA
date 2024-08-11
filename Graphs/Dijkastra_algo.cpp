#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, list<pair<int, int>>> createAdjList(vector<vector<int>> &edges, int e)
{
    unordered_map<int, list<pair<int, int>>> adjList;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    return adjList;
}

vector<int> dijkstra_using_min_heap_pq(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adjList = createAdjList(vec, edges);

    vector<int> dist(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int node = top.second;
        int nodeDist = top.first;

        for (auto neighbour : adjList[node])
        {
            if (nodeDist + neighbour.second < dist[neighbour.first])
            {

                dist[neighbour.first] = nodeDist + neighbour.second;
                pq.push({dist[neighbour.first], neighbour.first});
            }
        }
    }

    return dist;
}

vector<int> dijkstra_using_set(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adjList = createAdjList(vec, edges);

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        auto top = *(st.begin());
        st.erase(st.begin());

        int node = top.second;
        int nodeDist = top.first;

        for (auto neighbour : adjList[node])
        {
            if (nodeDist + neighbour.second < dist[neighbour.first])
            {

                dist[neighbour.first] = nodeDist + neighbour.second;
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }

    return dist;
}
