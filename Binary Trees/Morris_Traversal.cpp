#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node *root);
void createTreeLOT(Node *&root);

void morrisTraversal(Node *root)
{
    Node *curr, *pre;

    if (root == nullptr)
        return;

    curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->right != nullptr && pre->right != curr)
                pre = pre->right;

            if (pre->right == nullptr)
            {
                pre->right = curr;
                curr = curr->left;
            }

            else
            {
                pre->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

int main()
{
    Node *root;

    createTreeLOT(root);
    // 1 2 3 4 5 -1 6 -1 7 -1 -1 -1 8 -1 -1 -1 -1
    inOrderTraversal(root);
    cout << endl;
    morrisTraversal(root);
}

void createTreeLOT(Node *&root)
{

    cout << "Enter Data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        cout << "Enter data for left of " << frontNode->data << ":" << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            frontNode->left = new Node(leftData);
            q.push(frontNode->left);
        }

        cout << "Enter data for right of " << frontNode->data << ":" << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            frontNode->right = new Node(rightData);
            q.push(frontNode->right);
        }
    }
}

void inOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
