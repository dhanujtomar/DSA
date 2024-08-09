#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
class Graph
{
    vector<vector<T>> adj;

public:
    Graph(int n) : adj(n + 1) {}
    void addEdge(T u, T v, bool directed)
    {
        // directed -> 0    -   undirected
        // directed -> 1    -   directed

        // create an edge from u to v
        adj[u].push_back(v);

        // create an edge from v to u if directed graph
        if (!directed)
            adj[v].push_back(u);
    }

    vector<int> bfs()
    {
        map<int, bool> visited;
        queue<int> q;
        q.push(0);
        visited[0] = true;

        vector<int> ans;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (int node : adj[frontNode])
            {
                if (!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }

        return ans;
    }

    void dfsUtil(map<int, bool> &visited, vector<int> &ans, int element)
    {
        visited[element] = true;

        ans.push_back(element);

        for (int node : adj[element])
        {
            if (!visited[node])
                dfsUtil(visited, ans, node);
        }
    }

    vector<int> dfs()
    {
        map<int, bool> visited;
        vector<int> ans;

        dfsUtil(visited, ans, 0);
        return ans;
    }

    void printAdjList()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << "->";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    Graph<int> g(n);

    // Create Graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    // print adjList of graph
    g.printAdjList();

    return 0;
}