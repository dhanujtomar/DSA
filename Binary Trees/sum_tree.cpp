#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;

    // Nodes
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(Node *root);
void buildFromLevelOrder(Node *&root);

pair<bool, int> fastSum(Node *root)
{
    if (root == nullptr)
    {
        return {true, 0};
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return {true, root->data};
    }
    pair<bool, int> leftAns = fastSum(root->left);
    pair<bool, int> rightAns = fastSum(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool cond = root->data == leftAns.second + rightAns.second;

    if (left && right && cond)
    {
        return {true, 2 * root->data};
    }
    return {false, 2 * root->data};
}

int main()
{
    Node *root;

    // Build
    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 -- sum_tree false
    // 6 3 3 1 2 3 -1 -1 -1 -1 -1 -1 -1 -- sum_tree true
    // 3 1 2  -- true

    // Traverse
    levelOrderTraversal(root);

    cout << fastSum(root).first;

    return 0;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}
