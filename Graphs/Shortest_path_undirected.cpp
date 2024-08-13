#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Graph
{
    unordered_map<int, list<int>> adjList;
    int n;

public:
    Graph(int n) : n(n) {}

    // Step 1
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Step 2

    vector<int> shortestPath(int src, int dest)
    {
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        queue<int> q;

        parent[src] = -1;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (int neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    parent[neighbour] = frontNode;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        int curr = dest;
        vector<int> ans;
        ans.push_back(curr);

        while (curr != src)
        {
            curr = parent[curr];
            ans.push_back(curr);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
