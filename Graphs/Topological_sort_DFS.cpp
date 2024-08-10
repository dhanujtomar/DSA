#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> createAdjList(vector<vector<int>> &edges, int v, int e)
{
    vector<list<int>> adjList(v);

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
    return adjList;
}

void topoSort(vector<list<int>> &adjList, vector<bool> &visited, stack<int> &s, int node)
{
    visited[node] = true;

    for (int neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            topoSort(adjList, visited, s, neighbour);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<list<int>> adjList = createAdjList(edges, v, e);
    vector<bool> visited(v);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(adjList, visited, s, i);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}