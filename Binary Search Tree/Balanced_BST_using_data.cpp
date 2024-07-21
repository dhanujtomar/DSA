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

void inorder(TreeNode<int> *root, vector<int> &sorted)
{
    if (root == nullptr)
        return;

    inorder(root->left, sorted);
    sorted.push_back(root->data);
    inorder(root->right, sorted);
}

TreeNode<int> *balanceBST(int s, int e, vector<int> sorted)
{
    if (s > e)
        return nullptr;

    int mid = s + (e - s) / 2;

    TreeNode<int> *root = new TreeNode<int>(sorted[mid]);
    root->left = balanceBST(s, mid - 1, sorted);
    root->right = balanceBST(mid + 1, e, sorted);

    return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> sorted;
    inorder(root, sorted);

    return balanceBST(0, sorted.size() - 1, sorted);
}
