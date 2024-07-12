#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void print(Node *head);
void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&tail, int val);

void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node *add(Node *head1, Node *head2)
{
    int carry = 0;
    int sum = 0;
    int digit = 0;
    Node *start = head2;
    while (head1 != nullptr)
    {
        sum = head1->data + head2->data + carry;
        digit = sum % 10;
        carry = sum / 10;
        head2->data = digit;
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head2 != nullptr)
    {
        sum = head2->data + carry;
        digit = sum % 10;
        carry = sum / 10;
        head2->data = digit;
        head2 = head2->next;
    }
    if (carry != 0)
    {
        Node *temp = new Node(carry);
        head2->next = temp;
    }
    /*
    while (carry != 0)
    {
        digit = carry % 10;
        carry /= 10;
        Node *temp = new Node(digit);
        head2->next = temp;
        head2 = head2->next;
    }
    */
    return start;
}

int main()
{
    // head
    Node *head1 = new Node(5);
    Node *head2 = new Node(5);
    // tail
    // insertion
    insertAtHead(head1, 4);
    // insertAtHead(head1, 3);
    insertAtHead(head2, 4);
    insertAtHead(head2, 3);
    // insertAtHead(head2, 6);

    print(head1);
    print(head2);

    reverse(head1);
    reverse(head2);

    Node *head3 = add(head1, head2);

    reverse(head3);

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