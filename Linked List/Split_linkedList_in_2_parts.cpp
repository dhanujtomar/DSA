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
void insertAtTail(Node *&tail, int val);
void print(Node *head);

pair<Node *, Node *> split(Node *head)
{
    Node *fast = head->next->next;
    Node *slow = head->next;

    while (fast != head && fast->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *next = slow;
    fast = head;

    while (fast->next != slow)
    {
        fast = fast->next;
        next = next->next;
    }

    while (next->next != head)
    {
        next = next->next;
    }

    fast->next = head;
    next->next = slow;

    return {head, slow};
}

int main()
{
    // head
    Node *head = new Node(1);
    // tail
    Node *tail = head;
    // insertion
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    // insertAtHead(head, 6);

    tail->next = head;

    cout << "Main List: ";
    print(head);

    cout << endl;

    pair<Node *, Node *> p = split(head);

    // First part
    cout << "Frst Part: ";
    print(p.first);
    cout << endl;

    // Second part
    cout << "Scnd Part: ";
    print(p.second);
    cout << endl;

    return 0;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr && temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}