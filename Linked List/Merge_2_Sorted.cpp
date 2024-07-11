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

Node *merge(Node *head1, Node *head2)
{
    Node *first = head1;
    Node *second = head1->next;
    Node *temp = head2;

    while (second != nullptr)
    {
        if (first->data <= temp->data && temp->data < second->data)
        {
            first->next = temp;
            head2 = head2->next;
            temp->next = second;
            temp = head2;
            first = first->next;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
    first->next = head2;
    return head1;
}

int main()
{
    // head
    Node *head1 = new Node(1);
    Node *head2 = new Node(2);
    // tail
    Node *tail1 = head1;
    Node *tail2 = head2;
    // insertion
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 5);
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 5);
    insertAtTail(tail2, 6);

    print(head1);
    print(head2);

    Node *head3 = merge(head1, head2);

    print(head3);

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
    cout << endl;
}