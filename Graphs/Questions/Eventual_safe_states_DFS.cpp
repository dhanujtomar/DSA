#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<int> adjList[], vector<bool> &visited, vector<bool> &dfsVis, vector<bool> &check)
    {
        visited[node] = true;
        dfsVis[node] = true;

        for (int neighbour : adjList[node])
        {
            if (!visited[neighbour])
            {
                bool ans = dfs(neighbour, adjList, visited, dfsVis, check);

                if (ans)
                {
                    return true;
                }
            }
            else if (dfsVis[neighbour])
            {
                return true;
            }
        }

        dfsVis[node] = false;
        check[node] = true;

        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {

        vector<bool> visited(V, false);
        vector<bool> dfsVis(V, false);
        vector<bool> check(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, dfsVis, check);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (check[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};