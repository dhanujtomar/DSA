#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<list<int>> graph(int V, vector<int> adj[])
    {
        vector<list<int>> adjList(V);

        for (int i = 0; i < V; i++)
        {
            for (int j : adj[i])
            {
                adjList[j].push_back(i);
            }
        }
        return adjList;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {

        vector<list<int>> adjList = graph(V, adj);

        vector<int> indegree(V);

        for (int i = 0; i < V; i++)
        {
            for (int j : adjList[i])
            {
                indegree[j]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (int i : adjList[frontNode])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};