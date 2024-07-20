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

// create a Binary Search Tree
void takeInput(Node *&root);
Node *insertIntoBST(Node *root, int data);

// Finding max & min values
Node* maxValue(Node *);
Node* minValue(Node *);

// Binary Tree Traversal
void levelOrderTraversal(Node *root);

// Delete Node From BST

Node *deleteFromBST(Node *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if(root->left ==nullptr && root->right == nullptr){
            delete root;
            return NULL;
        }

        // 1 child
        if(root->left !=nullptr && root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }else if(root->left ==nullptr && root->right != nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        else{
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
        }

    }
    if (root->data > val)
        root->left = deleteFromBST(root->left, val);
    else
        root->right = deleteFromBST(root->right, val);
}

int main()
{
    Node *root = nullptr;

    takeInput(root);
    // 50 20 70 10 30 90 110 -1

    cout << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << minValue(root) << endl;
    cout << maxValue(root) << endl;

    return 0;
}

Node* maxValue(Node *root)
{
    Node *temp = root;

    while (temp->right != nullptr)
        temp = temp->right;

    return temp;
}

Node* minValue(Node *root)
{
    Node *temp = root;

    while (temp->left != nullptr)
        temp = temp->left;

    return temp;
}

Node *insertIntoBST(Node *root, int data)
{
    // base case
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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
                // queue still has some child nodes
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
