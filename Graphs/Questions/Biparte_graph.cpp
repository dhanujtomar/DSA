#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &nodes, bool green)
    {
        visited[node] = true;

        nodes[node] = green;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool ans = dfs(neighbour, node, adj, visited, nodes, !green);

                if (!ans)
                    return false;
            }
            else if (parent != neighbour)
            {
                if (nodes[neighbour] == green)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adjList[])
    {

        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++)
        {
            for (int j : adjList[i])
            {
                adj[i].push_back(j);
            }
        }

        vector<int> nodes(V, -1);

        vector<bool> visited(V, false);

        bool green = true;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = dfs(i, -1, adj, visited, nodes, green);

                if (!ans)
                    return false;
            }
        }

        return true;
    }
};