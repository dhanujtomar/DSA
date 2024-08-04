#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    int countNode(struct Node *root)
    {
        if (root == nullptr)
            return 0;

        int ans = 1 + countNode(root->left) + countNode(root->right);

        return ans;
    }

    bool isCBT(struct Node *root, int index, int count)
    {
        if (root == nullptr)
            return true;

        if (index >= count)
            return false;
        else
        {
            bool left = isCBT(root->left, 2 * index + 1, count);
            bool right = isCBT(root->right, 2 * index + 2, count);

            return left & right;
        }
    }

    bool isMaxOrder(struct Node *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return true;

        if (root->right == nullptr)
            return (root->data > root->left->data);
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            bool check = (root->data > root->left->data && root->data > root->right->data);

            return left & right & check;
        }
    }

public:
    bool isHeap(struct Node *tree)
    {
        int index = 0;
        int totalCount = countNode(tree);
        if (!isCBT(tree, index, totalCount))
            return false;

        return isMaxOrder(tree);
    }
};

int main()
{

    return 0;
}