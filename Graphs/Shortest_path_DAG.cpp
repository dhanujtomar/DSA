#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <vector>

using namespace std;

// Step 1: Create adj Matrix
// Step 2: find Topological Sort
// Step 3: Create and add elements to distance array (Src->0)

class Graph
{
    unordered_map<int, list<pair<int, int>>> adjList; // s1
    unordered_map<int, bool> visited;
    int n;
    stack<int> s;     // s2
    vector<int> dist; //  s3

public:
    Graph(int n) : n(n), dist(n, INT_MAX) {}

    // Step 1
    void addEdge(int u, int v, int w);

    void dfs(int node); // this is a utilility function for topological sort

    // Step 2
    stack<int> TopoSort();

    // Step 3
    void getShortestPathUtil(int src);

    vector<int> getShortestPath(int src);
};

void Graph::addEdge(int u, int v, int w)
{
    adjList[u].push_back({v, w});
}

void Graph::dfs(int node)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour.first])
            dfs(neighbour.first);
    }

    s.push(node);
}

// Step 2
stack<int> Graph::TopoSort()
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    return s;
}

void Graph::getShortestPathUtil(int src)
{
    dist[src] = 0;

    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (dist[top] != INT_MAX)
        {
            for (auto neighbour : adjList[top])
            {
                if (dist[neighbour.first] > dist[top] + neighbour.second)
                {
                    dist[neighbour.first] = dist[top] + neighbour.second;
                }
            }
        }
    }
}

vector<int> Graph::getShortestPath(int src)
{
    TopoSort();
    getShortestPathUtil(1);
    return dist;
}

// Class Ends Here

// Main functions

void createGraph(Graph &g)
{
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
}

int main()
{
    Graph g(6);
    createGraph(g); // add edges

    vector<int> d = g.getShortestPath(1);

    for (int i : d)
    {
        if (i != INT_MAX)
            cout << i << " ";
        else
            cout << "INF" << " ";
    }

    return 0;
}