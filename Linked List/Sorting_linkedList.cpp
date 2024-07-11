#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertAtHead(Node *&head, int val);
void print(Node *head);

Node *sortList(Node *head)
{
    Node *temp = head;
    Node *zero = nullptr;
    Node *one = nullptr;
    Node *two = nullptr;
    Node *zeroHead = nullptr;
    Node *oneHead = nullptr;
    Node *twoHead = nullptr;

    while (temp != nullptr)
    {
        switch (temp->data)
        {
        case 0:
            if (zero == nullptr)
            {
                zero = zeroHead = temp;
            }
            else
            {
                zero->next = temp;
            }
            temp = temp->next;
            zero->next = nullptr;
            break;
        case 1:
            if (one == nullptr)
            {
                one = oneHead = temp;
            }
            else
            {
                one->next = temp;
            }
            temp = temp->next;
            one->next = nullptr;
            break;
        case 2:
            if (two == nullptr)
            {
                two = twoHead = temp;
            }
            else
            {
                two->next = temp;
            }
            temp = temp->next;
            two->next = nullptr;
            if (two->next != nullptr)
                two = two->next;
            break;
        }
    }

    temp = zeroHead;
    zero->next = oneHead;
    one->next = twoHead;

    return temp;
}

int main()
{
    // head
    Node *head = new Node(1);
    // tail
    Node *tail = head;
    // insertion
    insertAtHead(head, 0);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    print(head);
    cout << endl;
    head = sortList(head);
    print(head);

    return 0;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
