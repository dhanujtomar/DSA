#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void checkLeft(Node *root, vector<int> &ans)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return;
        }

        ans.push_back(root->data);

        if (root->left)
            checkLeft(root->left, ans);
        else
            checkLeft(root->right, ans);
    }

    void checkLeaves(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
            return;
        }

        checkLeaves(root->left, ans);
        checkLeaves(root->right, ans);
    }

    void checkRight(Node *root, vector<int> &ans)
    {
        if (root == nullptr || (root->right == nullptr && root->left == nullptr))
        {
            return;
        }

        if (root->right)
        {
            checkRight(root->right, ans);
        }
        else
        {
            checkRight(root->left, ans);
        }

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> ans;

        ans.push_back(root->data);

        checkLeft(root->left, ans);

        // checkLeaves(root,ans);
        checkLeaves(root->left, ans);
        checkLeaves(root->right, ans);

        checkRight(root->right, ans);

        return ans;
    }
};