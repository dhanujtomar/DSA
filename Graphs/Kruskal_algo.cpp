#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    cout << node << " ";
    return findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[u] > rank[v])
        parent[v] = u;

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    makeSet(parent, n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        // cout << "checking for" << edges[i][0] << ": ";
        int u = findParent(parent, edges[i][0]);

        // cout << endl
        //      << "checking for" << edges[i][1] << ": ";
        int v = findParent(parent, edges[i][1]);
        // cout << endl;
        int wt = edges[i][2];

        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    // for (int i : parent)
    // 	cout << i << " ";
    // cout << endl;

    return minWeight;
}

pair<vector<vector<int>>, int> createGraph_1()
{
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 4, 1},
        {1, 5, 4},
        {4, 5, 9},
        {4, 3, 5},
        {2, 4, 3},
        {2, 3, 3},
        {2, 6, 7},
        {3, 6, 8}};

    return {edges, 7};
}

pair<vector<vector<int>>, int> createGraph_2()
{
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 3, 2},
        {3, 4, 6},
        {4, 5, 2},
        {5, 1, 1}};

    return {edges, 6};
}

pair<vector<vector<int>>, int> createGraph_3()
{
    vector<vector<int>> edges = {
        {7, 6, 1},
        {8, 2, 2},
        {6, 5, 2},
        {0, 1, 4},
        {2, 5, 4},
        {8, 6, 6},
        {2, 3, 7},
        {7, 8, 7},
        {0, 7, 8},
        {1, 2, 8},
        {3, 4, 9},
        {5, 4, 10},
        {1, 7, 11},
        {3, 5, 14}};

    return {edges, 9};
}

pair<vector<vector<int>>, int> createGraph_4()
{
    vector<vector<int>> edges = {
        {1, 4, 1},
        {1, 2, 2},
        {2, 3, 3},
        {2, 4, 3},
        {1, 5, 4},
        {3, 4, 5},
        {2, 6, 7},
        {3, 6, 8},
        {4, 5, 9}};

    return {edges, 7};
}

int main()
{
    auto graph = createGraph_4();
    vector<vector<int>> edges = graph.first;

    int n = graph.second;

    int ans = minimumSpanningTree(edges, n);
    cout << endl;

    cout << "Minimum spanning tree sum: " << ans;

    return 0;
}