#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//driver structure
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


//main solution

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        queue<Node *> q;
        bool leftToRight = true;
        q.push(root);
        vector<int> ans;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> store(size);

            for (int i = 0; i < size; i++)
            {
                Node *frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                store[index] = frontNode->data;

                if (frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if (frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }
            leftToRight = !leftToRight;
            for (int x : store)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};