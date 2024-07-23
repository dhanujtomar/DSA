#include <iostream>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void convertToSortedDLL(TreeNode *root, TreeNode *&head)
{
    if (root == nullptr)
        return;

    convertToSortedDLL(root->right, head);

    root->right = head;

    if (head != nullptr)
        head = head->left;

    head = root;

    convertToSortedDLL(root->left, head);
}

int main()
{
    TreeNode *root;
    TreeNode *head = nullptr;
    convertToSortedDLL(root, head);
}