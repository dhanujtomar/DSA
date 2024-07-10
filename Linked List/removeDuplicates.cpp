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

void removeDuplicates(Node *head)
{
    Node *first = head;

    while (first->next != nullptr)
    {
        if (first->data == first->next->data)
        {
            Node *temp = first->next;
            first->next = first->next->next;
            delete temp;
            continue;
        }
        first = first->next;
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
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 6);

    insertAtTail(tail, 0);

    print(head);

    removeDuplicates(head);
    cout << endl;

    print(head);
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
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}