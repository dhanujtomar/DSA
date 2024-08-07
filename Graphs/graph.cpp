#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
class Graph
{
    map<T, vector<T>> adj;

public:
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

    void printAdjList()
    {
        for (auto x : adj)
        {
            cout << x.first << " -> ";
            for (auto y : x.second)
                cout << y << " ";
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

    Graph<int> g;

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