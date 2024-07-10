#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

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
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
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

    insertAtTail(tail, 0);
    insertAtTail(tail, -1);
    insertAtTail(tail, -2);

    print(head);
    cout << endl;
    print(head);

    return 0;
}