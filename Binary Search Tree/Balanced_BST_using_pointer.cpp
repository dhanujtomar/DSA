
// https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int> *root, vector<TreeNode<int> *> &sorted)
{
    if (root == nullptr)
        return;

    inorder(root->left, sorted);
    sorted.push_back(root);
    inorder(root->right, sorted);
}

TreeNode<int> *Balanced(TreeNode<int> *root, int s, int e, vector<TreeNode<int> *> &sorted)
{
    if (root == nullptr)
        return nullptr;

    if (s >= e)
        return nullptr;

    int mid = s + (e - s) / 2;

    root->left = Balanced(sorted[mid], s, mid - 1, sorted);
    root->right = Balanced(sorted[mid], mid + 1, e, sorted);

    return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    // Write your code here.
    vector<TreeNode<int> *> sorted;
    inorder(root, sorted);

    int s = 0, e = sorted.size() - 1;
    int mid = s + (e - s) / 2;

    root = sorted[mid];

    root->left = Balanced(root, 0, mid - 1, sorted);
    root->right = Balanced(root, mid + 1, e, sorted);

    return root;
}