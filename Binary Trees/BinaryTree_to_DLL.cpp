#include <iostream>
#include <vector>

using namespace std;

// Tree Structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// This function should return head to the DLL
class Solution
{
public:
    void inorder(Node *root, vector<Node *> &in)
    {
        if (root == nullptr)
            return;

        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }
    // Function to convert binary tree to doubly linked list and return it.

    void solve(vector<Node *> &in)
    {
        for (int i = 0; i < in.size(); i++)
        {

            if (i == in.size() - 1)
                in[i]->right = nullptr;
            else
                in[i]->right = in[i + 1];

            if (i == 0)
                in[i]->left = nullptr;
            else
                in[i]->left = in[i - 1];
        }
    }

    Node *bToDLL(Node *root)
    {
        vector<Node *> in;

        inorder(root, in);

        solve(in);
        return in[0];
    }
};
