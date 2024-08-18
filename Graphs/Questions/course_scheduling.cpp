#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution
{
    vector<list<int>> createAdjList(int n, vector<vector<int>> &prerequisites)
    {
        vector<list<int>> adjList(n);

        for (auto edges : prerequisites)
        {
            int u = edges[1];
            int v = edges[0];

            adjList[u].push_back(v);
        }
        return adjList;
    }

public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        vector<list<int>> adjList = createAdjList(n, prerequisites);

        vector<int> indegree(n);

        for (int i = 0; i < adjList.size(); i++)
        {
            for (int j : adjList[i])
            {
                indegree[j]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
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

        if (ans.size() != n)
            return {};

        return ans;
    }
};