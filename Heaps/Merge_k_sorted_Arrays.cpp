// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    int currRow;
    int currIndex;

    node(int data, int row, int index) : data(data), currRow(row), currIndex(index) {}
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *tmp = new node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while (!minHeap.empty())
    {
        node *tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->currRow;
        int j = tmp->currIndex;

        if (j + 1 < kArrays[i].size())
        {
            node *newNode = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(newNode);
        }
    }

    return ans;
}
