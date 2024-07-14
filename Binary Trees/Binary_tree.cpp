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

Node *createTree(Node *root)
{
    cout << "enter data to node: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "enter data to enter in left of " << data << "Node: " << endl;
    root->left = createTree(root->left);
    cout << "enter data to enter in right of " << data << "Node: " << endl;
    root->right = createTree(root->left);

    return root;
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

void inOrder(Node *root)
{
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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

int main()
{
    Node *root;
    // root = createTree(root);
    buildFromLevelOrder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // inOrder(root);
    // cout << endl;
    // preOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;
    return 0;
}