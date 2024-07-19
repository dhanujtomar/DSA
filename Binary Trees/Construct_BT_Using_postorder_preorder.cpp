#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int findPosition(int in[], int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
                return i;
        }
        return -1;
    }

    Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
    {

        // base case
        if (index >= n || inOrderStart > inOrderEnd)
            return NULL;

        int element = pre[index++];
        Node *root = new Node(element);
        int position = findPosition(in, element, n);

        root->left = solve(in, pre, index, inOrderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        int preIndex = 0;
        Node *ans = solve(in, pre, preIndex, 0, n - 1, n);

        return ans;
    }
};