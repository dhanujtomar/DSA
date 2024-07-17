//  https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> m;
        // HD, Node-Data
        queue<pair<Node *, int>> q;

        if (root == nullptr)
            return {};

        vector<int> ans;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *frontNode = temp.first;
            int hd = temp.second;

            if (!m[hd])
            {
                m[hd] = frontNode->data;
            }

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        for (auto x : m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};